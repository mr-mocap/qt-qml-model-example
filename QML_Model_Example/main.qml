import QtQuick 2.12
import QtQuick.Controls 2.12
import QtQuick.Window 2.12
import MyApp 1.0

Window {
    visible: true
    width: 640
    height: 480
    title: qsTr("Hello World")

    Application {
        id: cpp_application
    }

    Rectangle {
        id: simple_string_list_rectangle
        width: 200
        border.width: 3
        border.color: "green"
        radius: 10
        anchors.margins: 10
        anchors.left: parent.left
        anchors.top: parent.top
        anchors.bottom: parent.bottom

        ListView {
            id: simple_string_list_view_1

            anchors.fill: parent
            anchors.margins: 10

            model: cpp_application.simpleStringListModel

            delegate: Rectangle {
                height: 25
                width: simple_string_list_view_1_delegate_text
                radius: 10
                border.width: 1
                border.color: "black"

                Text {
                    id: simple_string_list_view_1_delegate_text
                    text: modelData
                }
            }
        }
    }

    Rectangle {
        id: user_defined_qml_type_list_rectangle
        width: 200
        border.width: 3
        border.color: "orange"
        radius: 10
        anchors.margins: 10
        anchors.top: parent.top
        anchors.bottom: parent.bottom
        anchors.left: simple_string_list_rectangle.right

        ListView {
            id: user_defined_qml_type_list_1
            anchors.fill: parent
            anchors.margins: 10
            spacing: 10
            model: cpp_application.listModel1

            delegate: ItemDelegate {
                id: control
                height: control_info.height
                width: parent.width
                highlighted: ListView.isCurrentItem

                Column {
                    id: control_info
                    spacing: 5
                    padding: 5

                    Text {
                        text: "<b>Name:</b>  " + modelData.name
                    }
                    Text {
                        text: "<b>Occupation:</b>  " + modelData.occupation
                    }
                }
            }
        }
    }
}
