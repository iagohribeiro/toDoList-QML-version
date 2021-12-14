import QtQuick 2.12
import QtQuick.Window 2.12
import QtQuick.Controls 2.5
import QtQuick.Layouts 1.0


Window {
    width: 400
    height: 200
    title: "Edit Option"

    RowLayout {
        x: 63
        y: 30

        Rectangle {
            id: rectangle
            color: "#d14d5a"
            radius: 37
            Layout.preferredHeight: 68
            Layout.preferredWidth: 88
        }

        Rectangle {
            id: rectangle1
            color: "#e9c457"
            radius: 37
            Layout.preferredHeight: 68
            Layout.preferredWidth: 88
        }

        Rectangle {
            id: rectangle2
            color: "#73c18b"
            radius: 37
            border.color: "#73c18b"
            Layout.preferredHeight: 68
            Layout.preferredWidth: 88
        }
    }

    Button {
        id: resetButton
        x: 150
        y: 139
        text: qsTr("Reset")
        padding: 7
    }

}
