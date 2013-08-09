
/*
 * Copyright 2013, Blender Foundation.
 *
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License
 * as published by the Free Software Foundation; either version 2
 * of the License, or (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software Foundation,
 * Inc., 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301, USA.
 *
 * Contributor:
 *		Sergey Sharybin
 */

#ifndef _COM_PlaneTrackCommonOperation_h
#define _COM_PlaneTrackCommonOperation_h

#include <string.h>

#include "COM_NodeOperation.h"

#include "DNA_movieclip_types.h"
#include "DNA_tracking_types.h"

#include "BLI_listbase.h"
#include "BLI_string.h"

class PlaneTrackCommonOperation : public NodeOperation {
protected:
	MovieClip *m_movieClip;
	int m_framenumber;
	char m_trackingObjectName[64];
	char m_planeTrackName[64];

	float m_corners[4][2];            /* Corners coordinates in normalized space. */
	float m_frameSpaceCorners[4][2];  /* Corners coordinates in pixel space. */

	/**
	 * Determine the output resolution. The resolution is retrieved from the Renderer
	 */
	void determineResolution(unsigned int resolution[2], unsigned int preferredResolution[2]);

public:
	PlaneTrackCommonOperation();

	void setMovieClip(MovieClip *clip) {this->m_movieClip = clip;}
	void setTrackingObject(char *object) { BLI_strncpy(this->m_trackingObjectName, object, sizeof(this->m_trackingObjectName)); }
	void setPlaneTrackName(char *plane_track) { BLI_strncpy(this->m_planeTrackName, plane_track, sizeof(this->m_planeTrackName)); }
	void setFramenumber(int framenumber) {this->m_framenumber = framenumber;}

	void initExecution();
};

#endif
