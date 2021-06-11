// ScreenCapture.cpp : Defines the exported functions for the DLL.
//


#include "JNIScreenShot.h"
#include "DXGICapture.h"
#include <string>
#include <iostream>


JNIEXPORT void JNICALL Java_JNIScreenShot_captureScreen
(JNIEnv *env, jobject clz, jstring filePath, jint x, jint y, jint width, jint height) {
	HRESULT hr = S_OK;
	CDXGICapture dxgiCapture;
	jboolean isCopy;
	const char* pszOutputFileName = (env)->GetStringUTFChars(filePath, &isCopy);

	hr = dxgiCapture.Initialize();
	tagScreenCaptureFilterConfig config;

	// set default config
	RtlZeroMemory(&config, sizeof(config));
	config.ShowCursor = 1;
	config.SizeMode = tagFrameSizeMode_AutoSize;

	hr = dxgiCapture.SetConfig(config);
	hr = dxgiCapture.CaptureToFile((LPCTSTR)CA2WEX<>(pszOutputFileName), x, y, width, height);
	if (FAILED(hr))
	{
		printf("Error[0x%08X]: CDXGICapture::CaptureToFile failed.\n", hr);
	}
}

JNIEXPORT jint JNICALL Java_JNIScreenShot_getNumber
(JNIEnv *env, jobject clz) {
	return 2;
}

void test()
{
	HRESULT hr = S_OK;
	CDXGICapture dxgiCapture;
	jboolean isCopy;
	const char* pszOutputFileName = "foo.jpg";

	hr = dxgiCapture.Initialize();
	tagScreenCaptureFilterConfig config;

	// set default config
	RtlZeroMemory(&config, sizeof(config));
	config.ShowCursor = 1;
	config.SizeMode = tagFrameSizeMode_AutoSize;

	hr = dxgiCapture.SetConfig(config);
	hr = dxgiCapture.CaptureToFile((LPCTSTR)CA2WEX<>(pszOutputFileName), 801, 227, 1756, 1115);
	if (FAILED(hr))
	{
		printf("Error[0x%08X]: CDXGICapture::CaptureToFile failed.\n", hr);
	}
}