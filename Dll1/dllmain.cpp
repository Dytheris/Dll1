#include "pch.h"
#include <string>



BOOL WINAPI DllMain(HINSTANCE hDll, DWORD  dwReason, LPVOID lpReserved)
{
    switch (dwReason)
    {
    case DLL_PROCESS_ATTACH:
    case DLL_THREAD_ATTACH:
    case DLL_THREAD_DETACH:
    case DLL_PROCESS_DETACH:
        break;
    }
    return TRUE;
}

extern "C" __declspec(dllexport) double GetArea(double width, double height) {
    return width * height;
}

extern "C" __declspec(dllexport) double GetPerimeter(double width, double height) {
    return 2 * (width + height);
}

extern "C" __declspec(dllexport) const char* GetDescription(double width, double height) {
    static std::string description = "Rectangle (width = " + std::to_string(width) +
        ", height = " + std::to_string(height) + ")";
    return description.c_str();
}

extern "C" __declspec(dllexport) const char* SetColor(const char* color) {
    return color;
}

extern "C" __declspec(dllexport) const char* IsFilled(bool filled) {
    return filled ? "Filled" : "Not Filled";
}