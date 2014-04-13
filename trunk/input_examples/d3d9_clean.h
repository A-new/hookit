
//DO NOT COMPILE DIRECTLY, just for code auto-generators
// content changed a bit to make life easier for the auto-gens.

class IDirect3D9
{  
public:
    virtual __declspec(nothrow) HRESULT __stdcall QueryInterface( const IID & riid, void** ppvObj) = 0;
    virtual __declspec(nothrow) ULONG __stdcall AddRef(void) = 0;
    virtual __declspec(nothrow) ULONG __stdcall Release(void) = 0;    
    virtual __declspec(nothrow) HRESULT __stdcall RegisterSoftwareDevice( void* pInitializeFunction) = 0;
    virtual __declspec(nothrow) UINT __stdcall GetAdapterCount(void) = 0;
    virtual __declspec(nothrow) HRESULT __stdcall GetAdapterIdentifier( UINT Adapter,DWORD Flags,D3DADAPTER_IDENTIFIER9* pIdentifier) = 0;
    virtual __declspec(nothrow) UINT __stdcall GetAdapterModeCount( UINT Adapter,D3DFORMAT Format) = 0;
    virtual __declspec(nothrow) HRESULT __stdcall EnumAdapterModes( UINT Adapter,D3DFORMAT Format,UINT Mode,D3DDISPLAYMODE* pMode) = 0;
    virtual __declspec(nothrow) HRESULT __stdcall GetAdapterDisplayMode( UINT Adapter,D3DDISPLAYMODE* pMode) = 0;
    virtual __declspec(nothrow) HRESULT __stdcall CheckDeviceType( UINT Adapter,D3DDEVTYPE DevType,D3DFORMAT AdapterFormat,D3DFORMAT BackBufferFormat,BOOL bWindowed) = 0;
    virtual __declspec(nothrow) HRESULT __stdcall CheckDeviceFormat( UINT Adapter,D3DDEVTYPE DeviceType,D3DFORMAT AdapterFormat,DWORD Usage,D3DRESOURCETYPE RType,D3DFORMAT CheckFormat) = 0;
    virtual __declspec(nothrow) HRESULT __stdcall CheckDeviceMultiSampleType( UINT Adapter,D3DDEVTYPE DeviceType,D3DFORMAT SurfaceFormat,BOOL Windowed,D3DMULTISAMPLE_TYPE MultiSampleType,DWORD* pQualityLevels) = 0;
    virtual __declspec(nothrow) HRESULT __stdcall CheckDepthStencilMatch( UINT Adapter,D3DDEVTYPE DeviceType,D3DFORMAT AdapterFormat,D3DFORMAT RenderTargetFormat,D3DFORMAT DepthStencilFormat) = 0;
    virtual __declspec(nothrow) HRESULT __stdcall CheckDeviceFormatConversion( UINT Adapter,D3DDEVTYPE DeviceType,D3DFORMAT SourceFormat,D3DFORMAT TargetFormat) = 0;
    virtual __declspec(nothrow) HRESULT __stdcall GetDeviceCaps( UINT Adapter,D3DDEVTYPE DeviceType,D3DCAPS9* pCaps) = 0;
    virtual __declspec(nothrow) HMONITOR __stdcall GetAdapterMonitor( UINT Adapter) = 0;
    virtual __declspec(nothrow) HRESULT __stdcall CreateDevice( UINT Adapter,D3DDEVTYPE DeviceType,HWND hFocusWindow,DWORD BehaviorFlags,D3DPRESENT_PARAMETERS* pPresentationParameters,IDirect3DDevice9** ppReturnedDeviceInterface) = 0;
};
    

class IDirect3DDevice9
{    
public:
    virtual __declspec(nothrow) HRESULT __stdcall QueryInterface( const IID & riid, void** ppvObj) = 0;
    virtual __declspec(nothrow) ULONG __stdcall AddRef(void) = 0;
    virtual __declspec(nothrow) ULONG __stdcall Release(void) = 0;    
    virtual __declspec(nothrow) HRESULT __stdcall TestCooperativeLevel(void) = 0;
    virtual __declspec(nothrow) UINT __stdcall GetAvailableTextureMem(void) = 0;
    virtual __declspec(nothrow) HRESULT __stdcall EvictManagedResources(void) = 0;
    virtual __declspec(nothrow) HRESULT __stdcall GetDirect3D( IDirect3D9** ppD3D9) = 0;
    virtual __declspec(nothrow) HRESULT __stdcall GetDeviceCaps( D3DCAPS9* pCaps) = 0;
    virtual __declspec(nothrow) HRESULT __stdcall GetDisplayMode( UINT iSwapChain,D3DDISPLAYMODE* pMode) = 0;
    virtual __declspec(nothrow) HRESULT __stdcall GetCreationParameters( D3DDEVICE_CREATION_PARAMETERS *pParameters) = 0;
    virtual __declspec(nothrow) HRESULT __stdcall SetCursorProperties( UINT XHotSpot,UINT YHotSpot,IDirect3DSurface9* pCursorBitmap) = 0;
    virtual __declspec(nothrow) void __stdcall SetCursorPosition( int X,int Y,DWORD Flags) = 0;
    virtual __declspec(nothrow) BOOL __stdcall ShowCursor( BOOL bShow) = 0;
    virtual __declspec(nothrow) HRESULT __stdcall CreateAdditionalSwapChain( D3DPRESENT_PARAMETERS* pPresentationParameters,IDirect3DSwapChain9** pSwapChain) = 0;
    virtual __declspec(nothrow) HRESULT __stdcall GetSwapChain( UINT iSwapChain,IDirect3DSwapChain9** pSwapChain) = 0;
    virtual __declspec(nothrow) UINT __stdcall GetNumberOfSwapChains(void) = 0;
    virtual __declspec(nothrow) HRESULT __stdcall Reset( D3DPRESENT_PARAMETERS* pPresentationParameters) = 0;
    virtual __declspec(nothrow) HRESULT __stdcall Present( const RECT* pSourceRect,const RECT* pDestRect,HWND hDestWindowOverride,const RGNDATA* pDirtyRegion) = 0;
    virtual __declspec(nothrow) HRESULT __stdcall GetBackBuffer( UINT iSwapChain,UINT iBackBuffer,D3DBACKBUFFER_TYPE Type,IDirect3DSurface9** ppBackBuffer) = 0;
    virtual __declspec(nothrow) HRESULT __stdcall GetRasterStatus( UINT iSwapChain,D3DRASTER_STATUS* pRasterStatus) = 0;
    virtual __declspec(nothrow) HRESULT __stdcall SetDialogBoxMode( BOOL bEnableDialogs) = 0;
    virtual __declspec(nothrow) void __stdcall SetGammaRamp( UINT iSwapChain,DWORD Flags,const D3DGAMMARAMP* pRamp) = 0;
    virtual __declspec(nothrow) void __stdcall GetGammaRamp( UINT iSwapChain,D3DGAMMARAMP* pRamp) = 0;
    virtual __declspec(nothrow) HRESULT __stdcall CreateTexture( UINT Width,UINT Height,UINT Levels,DWORD Usage,D3DFORMAT Format,D3DPOOL Pool,IDirect3DTexture9** ppTexture,HANDLE* pSharedHandle) = 0;
    virtual __declspec(nothrow) HRESULT __stdcall CreateVolumeTexture( UINT Width,UINT Height,UINT Depth,UINT Levels,DWORD Usage,D3DFORMAT Format,D3DPOOL Pool,IDirect3DVolumeTexture9** ppVolumeTexture,HANDLE* pSharedHandle) = 0;
    virtual __declspec(nothrow) HRESULT __stdcall CreateCubeTexture( UINT EdgeLength,UINT Levels,DWORD Usage,D3DFORMAT Format,D3DPOOL Pool,IDirect3DCubeTexture9** ppCubeTexture,HANDLE* pSharedHandle) = 0;
    virtual __declspec(nothrow) HRESULT __stdcall CreateVertexBuffer( UINT Length,DWORD Usage,DWORD FVF,D3DPOOL Pool,IDirect3DVertexBuffer9** ppVertexBuffer,HANDLE* pSharedHandle) = 0;
    virtual __declspec(nothrow) HRESULT __stdcall CreateIndexBuffer( UINT Length,DWORD Usage,D3DFORMAT Format,D3DPOOL Pool,IDirect3DIndexBuffer9** ppIndexBuffer,HANDLE* pSharedHandle) = 0;
    virtual __declspec(nothrow) HRESULT __stdcall CreateRenderTarget( UINT Width,UINT Height,D3DFORMAT Format,D3DMULTISAMPLE_TYPE MultiSample,DWORD MultisampleQuality,BOOL Lockable,IDirect3DSurface9** ppSurface,HANDLE* pSharedHandle) = 0;
    virtual __declspec(nothrow) HRESULT __stdcall CreateDepthStencilSurface( UINT Width,UINT Height,D3DFORMAT Format,D3DMULTISAMPLE_TYPE MultiSample,DWORD MultisampleQuality,BOOL Discard,IDirect3DSurface9** ppSurface,HANDLE* pSharedHandle) = 0;
    virtual __declspec(nothrow) HRESULT __stdcall UpdateSurface( IDirect3DSurface9* pSourceSurface,const RECT* pSourceRect,IDirect3DSurface9* pDestinationSurface,const POINT* pDestPoint) = 0;
    virtual __declspec(nothrow) HRESULT __stdcall UpdateTexture( IDirect3DBaseTexture9* pSourceTexture,IDirect3DBaseTexture9* pDestinationTexture) = 0;
    virtual __declspec(nothrow) HRESULT __stdcall GetRenderTargetData( IDirect3DSurface9* pRenderTarget,IDirect3DSurface9* pDestSurface) = 0;
    virtual __declspec(nothrow) HRESULT __stdcall GetFrontBufferData( UINT iSwapChain,IDirect3DSurface9* pDestSurface) = 0;
    virtual __declspec(nothrow) HRESULT __stdcall StretchRect( IDirect3DSurface9* pSourceSurface,const RECT* pSourceRect,IDirect3DSurface9* pDestSurface,const RECT* pDestRect,D3DTEXTUREFILTERTYPE Filter) = 0;
    virtual __declspec(nothrow) HRESULT __stdcall ColorFill( IDirect3DSurface9* pSurface,const RECT* pRect,D3DCOLOR color) = 0;
    virtual __declspec(nothrow) HRESULT __stdcall CreateOffscreenPlainSurface( UINT Width,UINT Height,D3DFORMAT Format,D3DPOOL Pool,IDirect3DSurface9** ppSurface,HANDLE* pSharedHandle) = 0;
    virtual __declspec(nothrow) HRESULT __stdcall SetRenderTarget( DWORD RenderTargetIndex,IDirect3DSurface9* pRenderTarget) = 0;
    virtual __declspec(nothrow) HRESULT __stdcall GetRenderTarget( DWORD RenderTargetIndex,IDirect3DSurface9** ppRenderTarget) = 0;
    virtual __declspec(nothrow) HRESULT __stdcall SetDepthStencilSurface( IDirect3DSurface9* pNewZStencil) = 0;
    virtual __declspec(nothrow) HRESULT __stdcall GetDepthStencilSurface( IDirect3DSurface9** ppZStencilSurface) = 0;
    virtual __declspec(nothrow) HRESULT __stdcall BeginScene(void) = 0;
    virtual __declspec(nothrow) HRESULT __stdcall EndScene(void) = 0;
    virtual __declspec(nothrow) HRESULT __stdcall Clear( DWORD Count,const D3DRECT* pRects,DWORD Flags,D3DCOLOR Color,float Z,DWORD Stencil) = 0;
    virtual __declspec(nothrow) HRESULT __stdcall SetTransform( D3DTRANSFORMSTATETYPE State,const D3DMATRIX* pMatrix) = 0;
    virtual __declspec(nothrow) HRESULT __stdcall GetTransform( D3DTRANSFORMSTATETYPE State,D3DMATRIX* pMatrix) = 0;
    virtual __declspec(nothrow) HRESULT __stdcall MultiplyTransform( D3DTRANSFORMSTATETYPE,const D3DMATRIX*) = 0;
    virtual __declspec(nothrow) HRESULT __stdcall SetViewport( const D3DVIEWPORT9* pViewport) = 0;
    virtual __declspec(nothrow) HRESULT __stdcall GetViewport( D3DVIEWPORT9* pViewport) = 0;
    virtual __declspec(nothrow) HRESULT __stdcall SetMaterial( const D3DMATERIAL9* pMaterial) = 0;
    virtual __declspec(nothrow) HRESULT __stdcall GetMaterial( D3DMATERIAL9* pMaterial) = 0;
    virtual __declspec(nothrow) HRESULT __stdcall SetLight( DWORD Index,const D3DLIGHT9*) = 0;
    virtual __declspec(nothrow) HRESULT __stdcall GetLight( DWORD Index,D3DLIGHT9*) = 0;
    virtual __declspec(nothrow) HRESULT __stdcall LightEnable( DWORD Index,BOOL Enable) = 0;
    virtual __declspec(nothrow) HRESULT __stdcall GetLightEnable( DWORD Index,BOOL* pEnable) = 0;
    virtual __declspec(nothrow) HRESULT __stdcall SetClipPlane( DWORD Index,const float* pPlane) = 0;
    virtual __declspec(nothrow) HRESULT __stdcall GetClipPlane( DWORD Index,float* pPlane) = 0;
    virtual __declspec(nothrow) HRESULT __stdcall SetRenderState( D3DRENDERSTATETYPE State,DWORD Value) = 0;
    virtual __declspec(nothrow) HRESULT __stdcall GetRenderState( D3DRENDERSTATETYPE State,DWORD* pValue) = 0;
    virtual __declspec(nothrow) HRESULT __stdcall CreateStateBlock( D3DSTATEBLOCKTYPE Type,IDirect3DStateBlock9** ppSB) = 0;
    virtual __declspec(nothrow) HRESULT __stdcall BeginStateBlock(void) = 0;
    virtual __declspec(nothrow) HRESULT __stdcall EndStateBlock( IDirect3DStateBlock9** ppSB) = 0;
    virtual __declspec(nothrow) HRESULT __stdcall SetClipStatus( const D3DCLIPSTATUS9* pClipStatus) = 0;
    virtual __declspec(nothrow) HRESULT __stdcall GetClipStatus( D3DCLIPSTATUS9* pClipStatus) = 0;
    virtual __declspec(nothrow) HRESULT __stdcall GetTexture( DWORD Stage,IDirect3DBaseTexture9** ppTexture) = 0;
    virtual __declspec(nothrow) HRESULT __stdcall SetTexture( DWORD Stage,IDirect3DBaseTexture9* pTexture) = 0;
    virtual __declspec(nothrow) HRESULT __stdcall GetTextureStageState( DWORD Stage,D3DTEXTURESTAGESTATETYPE Type,DWORD* pValue) = 0;
    virtual __declspec(nothrow) HRESULT __stdcall SetTextureStageState( DWORD Stage,D3DTEXTURESTAGESTATETYPE Type,DWORD Value) = 0;
    virtual __declspec(nothrow) HRESULT __stdcall GetSamplerState( DWORD Sampler,D3DSAMPLERSTATETYPE Type,DWORD* pValue) = 0;
    virtual __declspec(nothrow) HRESULT __stdcall SetSamplerState( DWORD Sampler,D3DSAMPLERSTATETYPE Type,DWORD Value) = 0;
    virtual __declspec(nothrow) HRESULT __stdcall ValidateDevice( DWORD* pNumPasses) = 0;
    virtual __declspec(nothrow) HRESULT __stdcall SetPaletteEntries( UINT PaletteNumber,const PALETTEENTRY* pEntries) = 0;
    virtual __declspec(nothrow) HRESULT __stdcall GetPaletteEntries( UINT PaletteNumber,PALETTEENTRY* pEntries) = 0;
    virtual __declspec(nothrow) HRESULT __stdcall SetCurrentTexturePalette( UINT PaletteNumber) = 0;
    virtual __declspec(nothrow) HRESULT __stdcall GetCurrentTexturePalette( UINT *PaletteNumber) = 0;
    virtual __declspec(nothrow) HRESULT __stdcall SetScissorRect( const RECT* pRect) = 0;
    virtual __declspec(nothrow) HRESULT __stdcall GetScissorRect( RECT* pRect) = 0;
    virtual __declspec(nothrow) HRESULT __stdcall SetSoftwareVertexProcessing( BOOL bSoftware) = 0;
    virtual __declspec(nothrow) BOOL __stdcall GetSoftwareVertexProcessing(void) = 0;
    virtual __declspec(nothrow) HRESULT __stdcall SetNPatchMode( float nSegments) = 0;
    virtual __declspec(nothrow) float __stdcall GetNPatchMode(void) = 0;
    virtual __declspec(nothrow) HRESULT __stdcall DrawPrimitive( D3DPRIMITIVETYPE PrimitiveType,UINT StartVertex,UINT PrimitiveCount) = 0;
    virtual __declspec(nothrow) HRESULT __stdcall DrawIndexedPrimitive( D3DPRIMITIVETYPE,INT BaseVertexIndex,UINT MinVertexIndex,UINT NumVertices,UINT startIndex,UINT primCount) = 0;
    virtual __declspec(nothrow) HRESULT __stdcall DrawPrimitiveUP( D3DPRIMITIVETYPE PrimitiveType,UINT PrimitiveCount,const void* pVertexStreamZeroData,UINT VertexStreamZeroStride) = 0;
    virtual __declspec(nothrow) HRESULT __stdcall DrawIndexedPrimitiveUP( D3DPRIMITIVETYPE PrimitiveType,UINT MinVertexIndex,UINT NumVertices,UINT PrimitiveCount,const void* pIndexData,D3DFORMAT IndexDataFormat,const void* pVertexStreamZeroData,UINT VertexStreamZeroStride) = 0;
    virtual __declspec(nothrow) HRESULT __stdcall ProcessVertices( UINT SrcStartIndex,UINT DestIndex,UINT VertexCount,IDirect3DVertexBuffer9* pDestBuffer,IDirect3DVertexDeclaration9* pVertexDecl,DWORD Flags) = 0;
    virtual __declspec(nothrow) HRESULT __stdcall CreateVertexDeclaration( const D3DVERTEXELEMENT9* pVertexElements,IDirect3DVertexDeclaration9** ppDecl) = 0;
    virtual __declspec(nothrow) HRESULT __stdcall SetVertexDeclaration( IDirect3DVertexDeclaration9* pDecl) = 0;
    virtual __declspec(nothrow) HRESULT __stdcall GetVertexDeclaration( IDirect3DVertexDeclaration9** ppDecl) = 0;
    virtual __declspec(nothrow) HRESULT __stdcall SetFVF( DWORD FVF) = 0;
    virtual __declspec(nothrow) HRESULT __stdcall GetFVF( DWORD* pFVF) = 0;
    virtual __declspec(nothrow) HRESULT __stdcall CreateVertexShader( const DWORD* pFunction,IDirect3DVertexShader9** ppShader) = 0;
    virtual __declspec(nothrow) HRESULT __stdcall SetVertexShader( IDirect3DVertexShader9* pShader) = 0;
    virtual __declspec(nothrow) HRESULT __stdcall GetVertexShader( IDirect3DVertexShader9** ppShader) = 0;
    virtual __declspec(nothrow) HRESULT __stdcall SetVertexShaderConstantF( UINT StartRegister,const float* pConstantData,UINT Vector4fCount) = 0;
    virtual __declspec(nothrow) HRESULT __stdcall GetVertexShaderConstantF( UINT StartRegister,float* pConstantData,UINT Vector4fCount) = 0;
    virtual __declspec(nothrow) HRESULT __stdcall SetVertexShaderConstantI( UINT StartRegister,const int* pConstantData,UINT Vector4iCount) = 0;
    virtual __declspec(nothrow) HRESULT __stdcall GetVertexShaderConstantI( UINT StartRegister,int* pConstantData,UINT Vector4iCount) = 0;
    virtual __declspec(nothrow) HRESULT __stdcall SetVertexShaderConstantB( UINT StartRegister,const BOOL* pConstantData,UINT  BoolCount) = 0;
    virtual __declspec(nothrow) HRESULT __stdcall GetVertexShaderConstantB( UINT StartRegister,BOOL* pConstantData,UINT BoolCount) = 0;
    virtual __declspec(nothrow) HRESULT __stdcall SetStreamSource( UINT StreamNumber,IDirect3DVertexBuffer9* pStreamData,UINT OffsetInBytes,UINT Stride) = 0;
    virtual __declspec(nothrow) HRESULT __stdcall GetStreamSource( UINT StreamNumber,IDirect3DVertexBuffer9** ppStreamData,UINT* pOffsetInBytes,UINT* pStride) = 0;
    virtual __declspec(nothrow) HRESULT __stdcall SetStreamSourceFreq( UINT StreamNumber,UINT Setting) = 0;
    virtual __declspec(nothrow) HRESULT __stdcall GetStreamSourceFreq( UINT StreamNumber,UINT* pSetting) = 0;
    virtual __declspec(nothrow) HRESULT __stdcall SetIndices( IDirect3DIndexBuffer9* pIndexData) = 0;
    virtual __declspec(nothrow) HRESULT __stdcall GetIndices( IDirect3DIndexBuffer9** ppIndexData) = 0;
    virtual __declspec(nothrow) HRESULT __stdcall CreatePixelShader( const DWORD* pFunction,IDirect3DPixelShader9** ppShader) = 0;
    virtual __declspec(nothrow) HRESULT __stdcall SetPixelShader( IDirect3DPixelShader9* pShader) = 0;
    virtual __declspec(nothrow) HRESULT __stdcall GetPixelShader( IDirect3DPixelShader9** ppShader) = 0;
    virtual __declspec(nothrow) HRESULT __stdcall SetPixelShaderConstantF( UINT StartRegister,const float* pConstantData,UINT Vector4fCount) = 0;
    virtual __declspec(nothrow) HRESULT __stdcall GetPixelShaderConstantF( UINT StartRegister,float* pConstantData,UINT Vector4fCount) = 0;
    virtual __declspec(nothrow) HRESULT __stdcall SetPixelShaderConstantI( UINT StartRegister,const int* pConstantData,UINT Vector4iCount) = 0;
    virtual __declspec(nothrow) HRESULT __stdcall GetPixelShaderConstantI( UINT StartRegister,int* pConstantData,UINT Vector4iCount) = 0;
    virtual __declspec(nothrow) HRESULT __stdcall SetPixelShaderConstantB( UINT StartRegister,const BOOL* pConstantData,UINT  BoolCount) = 0;
    virtual __declspec(nothrow) HRESULT __stdcall GetPixelShaderConstantB( UINT StartRegister,BOOL* pConstantData,UINT BoolCount) = 0;
    virtual __declspec(nothrow) HRESULT __stdcall DrawRectPatch( UINT Handle,const float* pNumSegs,const D3DRECTPATCH_INFO* pRectPatchInfo) = 0;
    virtual __declspec(nothrow) HRESULT __stdcall DrawTriPatch( UINT Handle,const float* pNumSegs,const D3DTRIPATCH_INFO* pTriPatchInfo) = 0;
    virtual __declspec(nothrow) HRESULT __stdcall DeletePatch( UINT Handle) = 0;
    virtual __declspec(nothrow) HRESULT __stdcall CreateQuery( D3DQUERYTYPE Type,IDirect3DQuery9** ppQuery) = 0;    
};


class IDirect3DStateBlock9
{ 
public:
    virtual __declspec(nothrow) HRESULT __stdcall QueryInterface( const IID & riid, void** ppvObj) = 0;
    virtual __declspec(nothrow) ULONG __stdcall AddRef(void) = 0;
    virtual __declspec(nothrow) ULONG __stdcall Release(void) = 0;
    virtual __declspec(nothrow) HRESULT __stdcall GetDevice( IDirect3DDevice9** ppDevice) = 0;
    virtual __declspec(nothrow) HRESULT __stdcall Capture(void) = 0;
    virtual __declspec(nothrow) HRESULT __stdcall Apply(void) = 0;
};

class IDirect3DSurface9
{
public:    
    virtual __declspec(nothrow) HRESULT __stdcall QueryInterface( const IID & riid, void** ppvObj) = 0;
    virtual __declspec(nothrow) ULONG __stdcall AddRef(void) = 0;
    virtual __declspec(nothrow) ULONG __stdcall Release(void) = 0;

    
    virtual __declspec(nothrow) HRESULT __stdcall GetDevice( IDirect3DDevice9** ppDevice) = 0;
    virtual __declspec(nothrow) HRESULT __stdcall SetPrivateData( const GUID & refguid,const void* pData,DWORD SizeOfData,DWORD Flags) = 0;
    virtual __declspec(nothrow) HRESULT __stdcall GetPrivateData( const GUID & refguid,void* pData,DWORD* pSizeOfData) = 0;
    virtual __declspec(nothrow) HRESULT __stdcall FreePrivateData( const GUID & refguid) = 0;
    virtual __declspec(nothrow) DWORD __stdcall SetPriority( DWORD PriorityNew) = 0;
    virtual __declspec(nothrow) DWORD __stdcall GetPriority(void) = 0;
    virtual __declspec(nothrow) void __stdcall PreLoad(void) = 0;
    virtual __declspec(nothrow) D3DRESOURCETYPE __stdcall GetType(void) = 0;
    virtual __declspec(nothrow) HRESULT __stdcall GetContainer( const IID & riid,void** ppContainer) = 0;
    virtual __declspec(nothrow) HRESULT __stdcall GetDesc( D3DSURFACE_DESC *pDesc) = 0;
    virtual __declspec(nothrow) HRESULT __stdcall LockRect( D3DLOCKED_RECT* pLockedRect,const RECT* pRect,DWORD Flags) = 0;
    virtual __declspec(nothrow) HRESULT __stdcall UnlockRect(void) = 0;
    virtual __declspec(nothrow) HRESULT __stdcall GetDC( HDC *phdc) = 0;
    virtual __declspec(nothrow) HRESULT __stdcall ReleaseDC( HDC hdc) = 0;
};

class IDirect3DSwapChain9
{    
public:
    virtual __declspec(nothrow) HRESULT __stdcall QueryInterface( const IID & riid, void** ppvObj) = 0;
    virtual __declspec(nothrow) ULONG __stdcall AddRef(void) = 0;
    virtual __declspec(nothrow) ULONG __stdcall Release(void) = 0;
    
    virtual __declspec(nothrow) HRESULT __stdcall Present( const RECT* pSourceRect,const RECT* pDestRect,HWND hDestWindowOverride,const RGNDATA* pDirtyRegion,DWORD dwFlags) = 0;
    virtual __declspec(nothrow) HRESULT __stdcall GetFrontBufferData( IDirect3DSurface9* pDestSurface) = 0;
    virtual __declspec(nothrow) HRESULT __stdcall GetBackBuffer( UINT iBackBuffer,D3DBACKBUFFER_TYPE Type,IDirect3DSurface9** ppBackBuffer) = 0;
    virtual __declspec(nothrow) HRESULT __stdcall GetRasterStatus( D3DRASTER_STATUS* pRasterStatus) = 0;
    virtual __declspec(nothrow) HRESULT __stdcall GetDisplayMode( D3DDISPLAYMODE* pMode) = 0;
    virtual __declspec(nothrow) HRESULT __stdcall GetDevice( IDirect3DDevice9** ppDevice) = 0;
    virtual __declspec(nothrow) HRESULT __stdcall GetPresentParameters( D3DPRESENT_PARAMETERS* pPresentationParameters) = 0;  
};
    
	


class IDirect3DTexture9
{
public:    
    virtual __declspec(nothrow) HRESULT __stdcall QueryInterface( const IID & riid, void** ppvObj) = 0;
    virtual __declspec(nothrow) ULONG __stdcall AddRef(void) = 0;
    virtual __declspec(nothrow) ULONG __stdcall Release(void) = 0;

    
    virtual __declspec(nothrow) HRESULT __stdcall GetDevice( IDirect3DDevice9** ppDevice) = 0;
    virtual __declspec(nothrow) HRESULT __stdcall SetPrivateData( const GUID & refguid,const void* pData,DWORD SizeOfData,DWORD Flags) = 0;
    virtual __declspec(nothrow) HRESULT __stdcall GetPrivateData( const GUID & refguid,void* pData,DWORD* pSizeOfData) = 0;
    virtual __declspec(nothrow) HRESULT __stdcall FreePrivateData( const GUID & refguid) = 0;
    virtual __declspec(nothrow) DWORD __stdcall SetPriority( DWORD PriorityNew) = 0;
    virtual __declspec(nothrow) DWORD __stdcall GetPriority(void) = 0;
    virtual __declspec(nothrow) void __stdcall PreLoad(void) = 0;
    virtual __declspec(nothrow) D3DRESOURCETYPE __stdcall GetType(void) = 0;
    virtual __declspec(nothrow) DWORD __stdcall SetLOD( DWORD LODNew) = 0;
    virtual __declspec(nothrow) DWORD __stdcall GetLOD(void) = 0;
    virtual __declspec(nothrow) DWORD __stdcall GetLevelCount(void) = 0;
    virtual __declspec(nothrow) HRESULT __stdcall SetAutoGenFilterType( D3DTEXTUREFILTERTYPE FilterType) = 0;
    virtual __declspec(nothrow) D3DTEXTUREFILTERTYPE __stdcall GetAutoGenFilterType(void) = 0;
    virtual __declspec(nothrow) void __stdcall GenerateMipSubLevels(void) = 0;
    virtual __declspec(nothrow) HRESULT __stdcall GetLevelDesc( UINT Level,D3DSURFACE_DESC *pDesc) = 0;
    virtual __declspec(nothrow) HRESULT __stdcall GetSurfaceLevel( UINT Level,IDirect3DSurface9** ppSurfaceLevel) = 0;
    virtual __declspec(nothrow) HRESULT __stdcall LockRect( UINT Level,D3DLOCKED_RECT* pLockedRect,const RECT* pRect,DWORD Flags) = 0;
    virtual __declspec(nothrow) HRESULT __stdcall UnlockRect( UINT Level) = 0;
    virtual __declspec(nothrow) HRESULT __stdcall AddDirtyRect( const RECT* pDirtyRect) = 0;
};

class IDirect3DVertexBuffer9
{
public:    
    virtual __declspec(nothrow) HRESULT __stdcall QueryInterface( const IID & riid, void** ppvObj) = 0;
    virtual __declspec(nothrow) ULONG __stdcall AddRef(void) = 0;
    virtual __declspec(nothrow) ULONG __stdcall Release(void) = 0;

    
    virtual __declspec(nothrow) HRESULT __stdcall GetDevice( IDirect3DDevice9** ppDevice) = 0;
    virtual __declspec(nothrow) HRESULT __stdcall SetPrivateData( const GUID & refguid,const void* pData,DWORD SizeOfData,DWORD Flags) = 0;
    virtual __declspec(nothrow) HRESULT __stdcall GetPrivateData( const GUID & refguid,void* pData,DWORD* pSizeOfData) = 0;
    virtual __declspec(nothrow) HRESULT __stdcall FreePrivateData( const GUID & refguid) = 0;
    virtual __declspec(nothrow) DWORD __stdcall SetPriority( DWORD PriorityNew) = 0;
    virtual __declspec(nothrow) DWORD __stdcall GetPriority(void) = 0;
    virtual __declspec(nothrow) void __stdcall PreLoad(void) = 0;
    virtual __declspec(nothrow) D3DRESOURCETYPE __stdcall GetType(void) = 0;
    virtual __declspec(nothrow) HRESULT __stdcall Lock( UINT OffsetToLock,UINT SizeToLock,void** ppbData,DWORD Flags) = 0;
    virtual __declspec(nothrow) HRESULT __stdcall Unlock(void) = 0;
    virtual __declspec(nothrow) HRESULT __stdcall GetDesc( D3DVERTEXBUFFER_DESC *pDesc) = 0;
};

class IDirect3DVertexDeclaration9
{
public:    
    virtual __declspec(nothrow) HRESULT __stdcall QueryInterface( const IID & riid, void** ppvObj) = 0;
    virtual __declspec(nothrow) ULONG __stdcall AddRef(void) = 0;
    virtual __declspec(nothrow) ULONG __stdcall Release(void) = 0;

    
    virtual __declspec(nothrow) HRESULT __stdcall GetDevice( IDirect3DDevice9** ppDevice) = 0;
    virtual __declspec(nothrow) HRESULT __stdcall GetDeclaration( D3DVERTEXELEMENT9* pElement,UINT* pNumElements) = 0;
};



class IDirect3DVolumeTexture9
{    
public:
    virtual __declspec(nothrow) HRESULT __stdcall QueryInterface( const IID & riid, void** ppvObj) = 0;
    virtual __declspec(nothrow) ULONG __stdcall AddRef(void) = 0;
    virtual __declspec(nothrow) ULONG __stdcall Release(void) = 0;
    
    virtual __declspec(nothrow) HRESULT __stdcall GetDevice( IDirect3DDevice9** ppDevice) = 0;
    virtual __declspec(nothrow) HRESULT __stdcall SetPrivateData( const GUID & refguid,const void* pData,DWORD SizeOfData,DWORD Flags) = 0;
    virtual __declspec(nothrow) HRESULT __stdcall GetPrivateData( const GUID & refguid,void* pData,DWORD* pSizeOfData) = 0;
    virtual __declspec(nothrow) HRESULT __stdcall FreePrivateData( const GUID & refguid) = 0;
    virtual __declspec(nothrow) DWORD __stdcall SetPriority( DWORD PriorityNew) = 0;
    virtual __declspec(nothrow) DWORD __stdcall GetPriority(void) = 0;
    virtual __declspec(nothrow) void __stdcall PreLoad(void) = 0;
    virtual __declspec(nothrow) D3DRESOURCETYPE __stdcall GetType(void) = 0;
    virtual __declspec(nothrow) DWORD __stdcall SetLOD( DWORD LODNew) = 0;
    virtual __declspec(nothrow) DWORD __stdcall GetLOD(void) = 0;
    virtual __declspec(nothrow) DWORD __stdcall GetLevelCount(void) = 0;
    virtual __declspec(nothrow) HRESULT __stdcall SetAutoGenFilterType( D3DTEXTUREFILTERTYPE FilterType) = 0;
    virtual __declspec(nothrow) D3DTEXTUREFILTERTYPE __stdcall GetAutoGenFilterType(void) = 0;
    virtual __declspec(nothrow) void __stdcall GenerateMipSubLevels(void) = 0;
    virtual __declspec(nothrow) HRESULT __stdcall GetLevelDesc( UINT Level,D3DVOLUME_DESC *pDesc) = 0;
    virtual __declspec(nothrow) HRESULT __stdcall GetVolumeLevel( UINT Level,IDirect3DVolume9** ppVolumeLevel) = 0;
    virtual __declspec(nothrow) HRESULT __stdcall LockBox( UINT Level,D3DLOCKED_BOX* pLockedVolume,const D3DBOX* pBox,DWORD Flags) = 0;
    virtual __declspec(nothrow) HRESULT __stdcall UnlockBox( UINT Level) = 0;
    virtual __declspec(nothrow) HRESULT __stdcall AddDirtyBox( const D3DBOX* pDirtyBox) = 0;
};


class IDirect3DCubeTexture9
{
public:    
    virtual __declspec(nothrow) HRESULT __stdcall QueryInterface( const IID & riid, void** ppvObj) = 0;
    virtual __declspec(nothrow) ULONG __stdcall AddRef(void) = 0;
    virtual __declspec(nothrow) ULONG __stdcall Release(void) = 0;

    
    virtual __declspec(nothrow) HRESULT __stdcall GetDevice( IDirect3DDevice9** ppDevice) = 0;
    virtual __declspec(nothrow) HRESULT __stdcall SetPrivateData( const GUID & refguid,const void* pData,DWORD SizeOfData,DWORD Flags) = 0;
    virtual __declspec(nothrow) HRESULT __stdcall GetPrivateData( const GUID & refguid,void* pData,DWORD* pSizeOfData) = 0;
    virtual __declspec(nothrow) HRESULT __stdcall FreePrivateData( const GUID & refguid) = 0;
    virtual __declspec(nothrow) DWORD __stdcall SetPriority( DWORD PriorityNew) = 0;
    virtual __declspec(nothrow) DWORD __stdcall GetPriority(void) = 0;
    virtual __declspec(nothrow) void __stdcall PreLoad(void) = 0;
    virtual __declspec(nothrow) D3DRESOURCETYPE __stdcall GetType(void) = 0;
    virtual __declspec(nothrow) DWORD __stdcall SetLOD( DWORD LODNew) = 0;
    virtual __declspec(nothrow) DWORD __stdcall GetLOD(void) = 0;
    virtual __declspec(nothrow) DWORD __stdcall GetLevelCount(void) = 0;
    virtual __declspec(nothrow) HRESULT __stdcall SetAutoGenFilterType( D3DTEXTUREFILTERTYPE FilterType) = 0;
    virtual __declspec(nothrow) D3DTEXTUREFILTERTYPE __stdcall GetAutoGenFilterType(void) = 0;
    virtual __declspec(nothrow) void __stdcall GenerateMipSubLevels(void) = 0;
    virtual __declspec(nothrow) HRESULT __stdcall GetLevelDesc( UINT Level,D3DSURFACE_DESC *pDesc) = 0;
    virtual __declspec(nothrow) HRESULT __stdcall GetCubeMapSurface( D3DCUBEMAP_FACES FaceType,UINT Level,IDirect3DSurface9** ppCubeMapSurface) = 0;
    virtual __declspec(nothrow) HRESULT __stdcall LockRect( D3DCUBEMAP_FACES FaceType,UINT Level,D3DLOCKED_RECT* pLockedRect,const RECT* pRect,DWORD Flags) = 0;
    virtual __declspec(nothrow) HRESULT __stdcall UnlockRect( D3DCUBEMAP_FACES FaceType,UINT Level) = 0;
    virtual __declspec(nothrow) HRESULT __stdcall AddDirtyRect( D3DCUBEMAP_FACES FaceType,const RECT* pDirtyRect) = 0;
};



class IDirect3DIndexBuffer9
{
public:    
    virtual __declspec(nothrow) HRESULT __stdcall QueryInterface( const IID & riid, void** ppvObj) = 0;
    virtual __declspec(nothrow) ULONG __stdcall AddRef(void) = 0;
    virtual __declspec(nothrow) ULONG __stdcall Release(void) = 0;
    
    virtual __declspec(nothrow) HRESULT __stdcall GetDevice( IDirect3DDevice9** ppDevice) = 0;
    virtual __declspec(nothrow) HRESULT __stdcall SetPrivateData( const GUID & refguid,const void* pData,DWORD SizeOfData,DWORD Flags) = 0;
    virtual __declspec(nothrow) HRESULT __stdcall GetPrivateData( const GUID & refguid,void* pData,DWORD* pSizeOfData) = 0;
    virtual __declspec(nothrow) HRESULT __stdcall FreePrivateData( const GUID & refguid) = 0;
    virtual __declspec(nothrow) DWORD __stdcall SetPriority( DWORD PriorityNew) = 0;
    virtual __declspec(nothrow) DWORD __stdcall GetPriority(void) = 0;
    virtual __declspec(nothrow) void __stdcall PreLoad(void) = 0;
    virtual __declspec(nothrow) D3DRESOURCETYPE __stdcall GetType(void) = 0;
    virtual __declspec(nothrow) HRESULT __stdcall Lock( UINT OffsetToLock,UINT SizeToLock,void** ppbData,DWORD Flags) = 0;
    virtual __declspec(nothrow) HRESULT __stdcall Unlock(void) = 0;
    virtual __declspec(nothrow) HRESULT __stdcall GetDesc( D3DINDEXBUFFER_DESC *pDesc) = 0;
};




class IDirect3DQuery9
{
    virtual __declspec(nothrow) HRESULT __stdcall QueryInterface( const IID & riid, void** ppvObj) = 0;
    virtual __declspec(nothrow) ULONG __stdcall AddRef(void) = 0;
    virtual __declspec(nothrow) ULONG __stdcall Release(void) = 0;

    virtual __declspec(nothrow) HRESULT __stdcall GetDevice( IDirect3DDevice9** ppDevice) = 0;
    virtual __declspec(nothrow) D3DQUERYTYPE __stdcall GetType(void) = 0;
    virtual __declspec(nothrow) DWORD __stdcall GetDataSize(void) = 0;
    virtual __declspec(nothrow) HRESULT __stdcall Issue( DWORD dwIssueFlags) = 0;
    virtual __declspec(nothrow) HRESULT __stdcall GetData( void* pData,DWORD dwSize,DWORD dwGetDataFlags) = 0;
};

class IDirect3DCubeTexture9
{
public:    
	virtual __declspec(nothrow) DWORD __stdcall banana(void) = 0;
	virtual __declspec(nothrow) DWORD __stdcall banana1(void) = 0;
	virtual __declspec(nothrow) DWORD __stdcall banana2(void) = 0;
}