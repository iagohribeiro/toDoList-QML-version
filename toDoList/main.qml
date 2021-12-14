import QtQuick 2.12
import QtQuick.Window 2.12
import QtQuick.Controls 2.5
import QtQuick.Layouts 1.0

import Tasks 1.0

Window {
    width: 640
    height: 480
    visible: true
    //title: qsTr("To-Do List")

    Grid {
        id: grid
        x: 163
        y: 110
        width: 314
        height: 45

        CheckBox {
            id: high
            text: qsTr("High")
        }

        CheckBox {
            id: medium
            text: qsTr("Medium")
            checked: false
        }

        CheckBox {
            id: low
            text: qsTr("Low")
            checked: false
        }

        CheckBox {
            id: none
            text: qsTr("None")
            checked: false
        }
    }

    TextField {
        id: textField
        x: 220
        y: 64
        text: qsTr("")
    }

    Button {
        id: submit
        x: 270
        y: 161
        text: qsTr("Submit")
        onClicked: toDoListItems.appendItem(textField.text)
        checkable: false
    }

     ListView {
        id: scrollView
        x: 30
        y: 215
        width: 580
        height: 200

        model: TaskModel{
            list: toDoListItems
        }

        delegate: RowLayout {
            width: parent.width

            CheckBox {
                id: checkBox
                checked: model.taskStatus
                onClicked: model.taskStatus = checked
            }

            Label {
                id: label
                text: model.description
                Layout.preferredHeight: 40
                Layout.preferredWidth: 190
            }

            Button {
                id: editButton
                text: qsTr("Edit")
            }

            ToolSeparator {
                id: toolSeparator
                Layout.preferredHeight: 40
                Layout.preferredWidth: 71
            }

            Button {
                id: deleteButton
                text: qsTr("Delete")
                onClicked: toDoListItems.removeItem()
            }
        }

    }

    Button {
        id: save
        x: 270
        y: 421
        text: qsTr("Save")
    }

}
