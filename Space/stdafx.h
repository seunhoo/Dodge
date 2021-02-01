#pragma once
#define Vec2 D3DXVECTOR2
#define Matrix D3DXMATRIX
#define SAFE_DELETE(x)if(x){delete x; x=NULL;}
#define Nor D3DXVec2Normalize

#include<Windows.h>
#include<stdio.h>
#include<iostream>
#include<d3d9.h>
#include<d3dx9.h>
//#include<dsound.h>
#include<map>
#include<list>
#include<ctime>
#include<vector>
#include<string>
#include<sstream>
#include<cmath>
#include<mmsystem.h>
//
#include"Singleton.h"
#include"Input.h"
#include"Renderer.h"
#include"App.h"
#include"Object.h"
#include"ObjectMgr.h"
#include"CollisionMgr.h"
#include"SceneDirector.h"
#include"TextFont.h"
#include"SoundMgr.h"
#include"Sprite.h"
#include"Animation.h"
#include"Player.h"
#include"Monster.h"
#include"Camera.h"
//
