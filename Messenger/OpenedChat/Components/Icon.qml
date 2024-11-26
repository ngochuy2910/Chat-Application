import QtQuick 2.0
import QtQuick.Effects

Image{
    id: icon

    property string color: ""
    property string path: ""

    fillMode: Image.PreserveAspectFit
    source: path

    layer{
        enabled: color != ""
        // effect: ColorOverlay {
        //     color: icon.color
        // }
    }

}
