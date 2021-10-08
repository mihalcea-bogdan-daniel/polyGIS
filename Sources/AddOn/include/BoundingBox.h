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
			Initialize a bounding box with width and height, starting from 0, 0 coord;
			*/
			BoundingBox(const double& width, const double& height);
			/**
			Initialize a bounding box with 4 coordinates;
			*/
			BoundingBox(
				const double& minX, 
				const double& minY, 
				const double& maxX, 
				const double& maxY);

			/**
			Initialize a bounding box with an array of API_Coord;
			*/
			BoundingBox(
				const GS::Array<API_Coord>& coordinates,
				const bool& absoluteOrigin = false
			);

			//============================Destructors==============================
			virtual ~BoundingBox();

			//============================Functions==============================
			/**
			Get the normalized coordinates, consider origin to lower left corner.
			*/
			virtual GS::Array<API_Coord> GetNormalizedCoordinates();
			
			/**
			Get the normalized coordinates with the origin located at the relativeToThisPoint parameter.
			*/
			virtual GS::Array<API_Coord> GetNormalizedCoordinates(const API_Coord& relativeToThisPoint);
			virtual BoundingBox GetNormalizedBoundingBox();
			
			/**
			Default set center relative to the current box margins.
			*/
			virtual void SetCenter();

			/*
			Set center to a given API_Coord point
			*/
			virtual void SetCenter(const API_Coord& center);
			void TranslateCoordinatesToAbsoluteOrigin();
		protected:
			API_Box box {0.0, 0.0, 1.0, 1.0};
			GS::Array<API_Coord> coordinates = {};
			API_Coord center = {0.5, 0.5};
		private:

		};

	}
}
