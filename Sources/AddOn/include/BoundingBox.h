#pragma once
#include "APIEnvir.h"
#include "ACAPinc.h"
namespace GIS {
	namespace BBOX {
		class BoundingBox
		{
		public:
			//============================Constructors=============================
			/**
			Default initialization
			*/
			BoundingBox();

			/**
			*Initialize a bounding box with width and height, starting from 0, 0 coord;
			*/
			BoundingBox(const double& width, const double& height);
			/**
			*Initialize a bounding box with 4 coordinates;
			*/
			BoundingBox(
				const double& minX, 
				const double& minY, 
				const double& maxX, 
				const double& maxY);
			BoundingBox(const GS::Array<API_Coord>& coordinates);

			//============================Destructors==============================
			virtual ~BoundingBox();

			//============================Functions==============================
			/*
			Get the normalized coordinates, consider origin to lower left corner.
			*/
			GS::Array<API_Coord> GetNormalizedCoordinates();
			
			/*
			Get the normalized coordinates with the origin located at the relativeToThisPoint parameter.
			*/
			virtual GS::Array<API_Coord> GetNormalizedCoordinates(const API_Coord& relativeToThisPoint);

			/*
			Default set center relative to the current box margins, right in the middle
			*/
			virtual void SetCenter();

			/*
			Set center to a given API_Coord point
			*/
			virtual void SetCenter(const API_Coord& _center);
		protected:
			API_Box box = {0.0, 0.0, 1.0, 1.0};
			GS::Array<API_Coord> coordinates = {};
			API_Coord center;
		private:

		};

	}
}
