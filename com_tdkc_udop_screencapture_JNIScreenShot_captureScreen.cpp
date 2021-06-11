#include "com_tdkc_udop_screencapture_JNIScreenShot.h"
#include "DXGICapture.h"
#include <string>
#include <iostream>


JNIEXPORT void JNICALL Java_com_tdkc_udop_screencapture_JNIScreenShot_captureScreen
(JNIEnv* env, jobject clz, jstring filePath, jint x, jint y, jint width, jint height) {
	CoInitialize(nullptr);
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


	const char* p = pszOutputFileName;
	const WCHAR* pwcsName; //LPCWSTR

	// required size
	int size = MultiByteToWideChar(CP_ACP, 0, p, -1, NULL, 0);
	// allocate it
	pwcsName = new WCHAR[size];
	MultiByteToWideChar(CP_ACP, 0, p, -1, (LPWSTR)pwcsName, size);

	hr = dxgiCapture.CaptureToFile((LPCTSTR)pwcsName, x, y, width, height);
	delete[] pwcsName;

	//hr = dxgiCapture.CaptureToFile((LPCTSTR)CA2WEX<>(pszOutputFileName), x, y, width, height);
	if (FAILED(hr))
	{
		printf("Error[0x%08X]: CDXGICapture::CaptureToFile failed.\n", hr);
	}
}

JNIEXPORT jint JNICALL Java_com_tdkc_udop_screencapture_JNIScreenShot_getNumber
(JNIEnv* env, jobject clz) {
	return 2;
}