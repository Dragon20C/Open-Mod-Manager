Scriptname TextureSet extends Form Hidden


; SKSE 64 additions built 2020-07-29 17:24:48.495000 UTC

; Returns the number of texture paths
int Function GetNumTexturePaths() native

; Returns the path of the texture
string Function GetNthTexturePath(int n) native

; Sets the path of the texture
Function SetNthTexturePath(int n, string texturePath) native