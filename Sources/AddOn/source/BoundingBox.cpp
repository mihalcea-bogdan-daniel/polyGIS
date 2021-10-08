#include	"APIEnvir.h"
#include	"ACAPinc.h"
#include	"StringConversion.hpp"
#include	"BoundingBox.h"

namespace GIS {
	namespace BBOX {

		BoundingBox::BoundingBox()
		{
		}

		BoundingBox::BoundingBox(
			const double &width,
			const double &height)
		{
			this->box.xMin = 0.0;
			this->box.xMax = width;
			this->box.yMin = 0.0;
			this->box.yMax = height;
			this->SetCenter();
		}

		BoundingBox::BoundingBox(
			const double& xMin,
			const double& yMin,
			const double& xMax,
			const double& yMax)
		{
			this->box.xMin = xMin;
			this->box.xMax = xMax;
			this->box.yMin = yMin;
			this->box.yMax = yMax;
			this->SetCenter();
		}

		BoundingBox::BoundingBox(
			const GS::Array<API_Coord>& coordinates, const bool& absoluteOrigin)
		{

			this->coordinates = coordinates;
			this->box.xMin = coordinates[0].x;
			this->box.xMax = coordinates[0].x;
			this->box.yMin = coordinates[0].y;
			this->box.yMax = coordinates[0].y;


			for (API_Coord currentCoordinate : coordinates) {
				if (currentCoordinate.x < this->box.xMin) {
					this->box.xMin = currentCoordinate.x;
				}
				if (currentCoordinate.y < this->box.yMin) {
					this->box.yMin = currentCoordinate.y;
				}
				if (currentCoordinate.x > this->box.xMax) {
					this->box.xMax = currentCoordinate.x;
				}
				if (currentCoordinate.y > this->box.yMax) {
					this->box.yMax = currentCoordinate.y;
				}
			}
			if (absoluteOrigin==true) {
				this->TranslateCoordinatesToAbsoluteOrigin();
			}
			this->SetCenter();
		}

		BoundingBox::~BoundingBox()
		{
		}

		GS::Array<API_Coord> BoundingBox::GetNormalizedCoordinates()
		{
			GS::Array<API_Coord> normalCoordinates = {};
			for (API_Coord currentCoord : this->coordinates) {

				API_Coord normalCoord = {
					(currentCoord.x - this->box.xMin) / (this->box.xMax - this->box.xMin),
					(currentCoord.y - this->box.yMin) / (this->box.yMax - this->box.yMin)
				};
				normalCoordinates.Push(normalCoord);

			}
			return normalCoordinates;
		}

		//TODO NEEDS DOUBLE CHECK NORMALIZATION
		GS::Array<API_Coord> BoundingBox::GetNormalizedCoordinates(const API_Coord& relativeToThisPoint)
		{
			GS::Array<API_Coord> normalCoordinates = {};
			for (API_Coord currentCoord : this->coordinates) {

				API_Coord normalCoord = {
					(currentCoord.x - relativeToThisPoint.x) / (this->box.xMax - relativeToThisPoint.x),
					(currentCoord.y - relativeToThisPoint.y) / (this->box.yMax - relativeToThisPoint.y)
				};
				normalCoordinates.Push(normalCoord);

			}
			return normalCoordinates;
		}

		BoundingBox BoundingBox::GetNormalizedBoundingBox()
		{
			return BoundingBox(this->GetNormalizedCoordinates());
		}

		void BoundingBox::SetCenter()
		{
			this->center = {
				(this->box.xMax - this->box.yMin) / 2.0,
				(this->box.yMax - this->box.yMin) / 2.0
			};
		}

		void BoundingBox::SetCenter(const API_Coord& center)
		{
			this->center = center;
		}
		void BoundingBox::TranslateCoordinatesToAbsoluteOrigin()
		{
			ACAPI_WriteReport("---Original Coordinates---", false);
			for (API_Coord c : this->coordinates)
			{
				ACAPI_WriteReport(GS::ValueToUniString(c.x)+ ", "+ GS::ValueToUniString(c.y), false);
				c.x = c.x - this->box.xMin;
				c.y = c.y - this->box.yMin;
			}
		}
	}
}