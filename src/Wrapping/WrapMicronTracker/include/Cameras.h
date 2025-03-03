/**************************************************************
*
*     Micron Tracker: Example C++ wrapper and Multi-platform demo
*   
*     Written by: 
*			Shi Sherebrin , Robarts Research Institute - London- Ontario , www.robarts.ca
*			Shahram Izadyar, Robarts Research Institute - London- Ontario , www.robarts.ca
*			Claudio Gatti, Ahmad Kolahi, Claron Technology - Toronto -Ontario, www.clarontech.com
*
*     Copyright Claron Technology 2000-2003
*
***************************************************************/


#ifndef __CAMERAS_H__
#define __CAMERAS_H__
#include <vector>
#include "MCamera.h"

//#define MaxCameras 5

//using namespace std;

class Cameras
{
public:
	Cameras();
	~Cameras();
	inline int getHandle() {return m_handle;};
	inline int	getCount() {return m_attachedCamNums;};
	int setHistogramEqualizeImages(bool on_off);
	bool getHistogramEqualizeImages();
	MCamera* getCamera(int index);


	int getShutterPreference() { return 0;}
	int setShutterPreference(int val) { return 0;}
	int getGainPreference() {return 0;}
	int setGainPreference(int val) {return 0;}

	int AttachAvailableCameras();
	void Detach();

	inline void setMarkersHandle(int markersHandle){m_markersHandle = markersHandle;};

	bool grabFrame(MCamera *cam = NULL); // returns true for success

	// need to lear how to hide it, and keep same access syntax
	std::vector<MCamera *> m_vCameras;


private:
	int getMTHome( char *, int);
	int m_handle;
	bool ownedByMe;
	MCamera* mCurrCam;
	MCamera*	mFailedCam;


	int m_attachedCamNums;
	int m_markersHandle;

};

#endif
