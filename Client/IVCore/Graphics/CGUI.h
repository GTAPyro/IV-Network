//========== IV:Multiplayer - https://github.com/IVMultiplayer/IVMultiplayer ==========
//
// File: CGUI.cpp
// Project: Client.Core
// Author: ViruZz <blazee14@gmail.com>
// License: See LICENSE in root directory
//
//==============================================================================

#include "CCore.h"
	
class CGUI 
{
public:
	enum eGUIView { GUI_MAIN = 0, GUI_SERVER = 1, GUI_NONE = 2 };
	CGUI(IDirect3DDevice9* pDevice);
	~CGUI();

	void Render();
	bool ProcessInput(UINT message, LPARAM lParam, WPARAM wParam);

	void SetScreenSize(int iWidth, int iHeight);
	void GetScreenSize(int* iWidth, int* iHeight);
	eGUIView GetView();
	void SetView(eGUIView view);
	void ClearView(eGUIView view);

	Gwen::Renderer::DirectX9* GetRenderer() { return m_pRenderer; }
	Gwen::Controls::Canvas* GetCanvas(eGUIView view);
private:
	// DX-based renderer
	Gwen::Renderer::DirectX9* m_pRenderer;

	CGUIView* m_pActiveView;
	CGUIView* m_pViews[GUI_NONE];

	int m_iScreenWidth;
	int m_iScreenHeight;
};