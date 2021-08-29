﻿#pragma once
#include <Windows.h>
#include <stdint.h>

#ifdef IB_AHKSEND_DLLEXPORT
#define DLLAPI extern "C" __declspec(dllexport)
#else
#define DLLAPI extern "C" __declspec(dllimport)
#endif

namespace Send {
    enum class Error : uint32_t {
        Success,
        InvalidArgument,
        LibraryNotFound,
        LibraryLoadFailed,
        LibraryError,
        DeviceCreateFailed,
        DeviceNotFound,
        DeviceOpenFailed
    };

    enum class SendType : uint32_t {
        AnyDriver,
        SendInput,
        Logitech,
        DD
    };

    using InitFlags = const uint32_t;
    struct Init {
        using T = InitFlags;
    };

    enum class HookCode : uint32_t {
        Off,
        On,
        InitOnly,
        Destroy
    };
}

DLLAPI Send::Error __stdcall IbSendInit(Send::SendType type, Send::InitFlags flags, void* argument);
DLLAPI void __stdcall IbSendDestroy();
DLLAPI void __stdcall IbSendSyncKeyStates();
DLLAPI UINT WINAPI IbSendInput(UINT cInputs, LPINPUT pInputs, int cbSize);
DLLAPI void __stdcall IbSendInputHook(Send::HookCode code);