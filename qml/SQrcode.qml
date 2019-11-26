import QtQuick 2.0
import syberh_qrcode 1.0

BarCodeMain {
    Component.onDestruction :{
        // 原生组件退出以后，状态栏有问题，手动设置黑背景
        gScreenInfo.setStatusBar(true);
        gScreenInfo.setStatusBarStyle("black");
    }
}
