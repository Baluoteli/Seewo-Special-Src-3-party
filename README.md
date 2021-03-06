# Seewo-Special-Src-3-party

*其他语言版本： [简体中文](README.zh.md)*

The Open Live Windows Sample App is an open-source demo that will help you get live video chat integrated directly into your windows applications using the Agora Video SDK.

With this sample app, you can:

- Join / leave channel
- Set role as broadcaster or audience
- Mute / unmute audio
- Change camera
- Setup resolution, frame rate and bit rate

This demo is written in **C++**

A tutorial demo can be found here: [Agora-Windows-Tutorial-1to1](https://github.com/AgoraIO/Agora-Windows-Tutorial-1to1)

Agora Video SDK supports iOS / Android / Windows / macOS etc. You can find demos of these platform here:

- [OpenLive-Android](https://github.com/AgoraIO/OpenLive-Android)
- [OpenLive-iOS](https://github.com/AgoraIO/OpenLive-iOS)
- [OpenLive-macOS](https://github.com/AgoraIO/OpenLive-macOS)

## Running the App
First, create a developer account at [Agora.io](https://dashboard.agora.io/signin/), and obtain an App ID. define the APP_ID with your App ID.

```
#define APP_ID _T("Your App ID")
```

Next, download the **Agora Video SDK** from [Agora.io SDK](https://www.agora.io/en/download/). Unzip the downloaded SDK package and copy the **sdk** to the project folder(the old one may be over written).

Finally, Open OpenLive.sln with your VC++ 2013(or higher) and build all solution and run.

Note：
  You may encounter crash when running this demo under debug mode. Please run this demo under release mode.
  
## Developer Environment Requirements
* VC++ 2013(or higher)
* Windows 7(or higher)

## Connect Us

- You can find full API document at [Document Center](https://docs.agora.io/en/)
- You can file bugs about this demo at [issue](https://github.com/AgoraIO/OpenLive-Windows/issues)

## License

The MIT License (MIT).
>>>>>>> first commit for seewo-special-src-3-party
