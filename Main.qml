import QtQuick 2.15
import QtQuick.Controls 2.15
import QtQuick.Layouts 1.15
import PathfindingEngine 1.0

ApplicationWindow{
    id: application
    visible: true
    title: "Transformers"
    width: 1200
    height: 800
    color: "#DDDDDD"

    // Global optimal path storage
    property var globalOptimalPath: []

    // PathfindingEngine instance at application level
    PathfindingEngine {
        id: pathfindingEngine
    }

    StackView {
        id: stackView
        anchors.fill: parent
        initialItem: camera
    }

    Component {
        id: camera

        Page {
            objectName: "cameraPage" // Add objectName for identification
            title: "Camera Feed"

            ColumnLayout {
                anchors.fill: parent
                spacing: 10

                RowLayout {
                    spacing: 20

                    Text {
                        id: title
                        text: "Camera Feed"
                        font.pointSize: 20
                        Layout.leftMargin: 10
                        Layout.topMargin: 5
                    }

                    Button {
                        text: "Map View"
                        onClicked: {
                            stackView.push(map)
                        }
                        Layout.alignment: Qt.AlignVCenter
                    }

                    Button {
                        text: "Remote Control"
                        onClicked: {
                            stackView.push(remoteControl)
                        }
                        Layout.alignment: Qt.AlignVCenter
                    }

                    Button {
                        text: "Thumbstick Control"
                        onClicked: {
                            stackView.push(thumbstickControl)
                        }
                        Layout.alignment: Qt.AlignVCenter
                    }
                }

                Rectangle { //this will be the actual camera feed from micro-controller
                    color: "lightgrey"
                    Layout.fillWidth: true
                    Layout.minimumWidth: 300
                    Layout.preferredWidth: 800
                    Layout.minimumHeight: 150
                    Layout.preferredHeight: 600
                    Layout.maximumHeight: 700

                    Text {
                        anchors.centerIn: parent
                        text: 'Camera View (' + parent.width + 'x' + parent.height + ')'
                    }

                    Rectangle {
                        color: "#F0E4D3"
                        width: 400
                        height: 300
                        anchors.top: parent.top
                        anchors.right: parent.right
                        anchors.margins: 10
                        radius: 5
                        border.color: "grey"
                        border.width: 1

                        // Mini terrain map
                        TopographicalMapView {
                            id: miniMap
                            anchors.fill: parent
                            anchors.margins: 5
                            showConnections: false // Hide connections in mini-map for cleaner view
                            showOptimalPath: true
                            optimalPath: globalOptimalPath // Bind to global path

                            // Watch for changes in globalOptimalPath and refresh
                            Connections {
                                target: application
                                function onGlobalOptimalPathChanged() {
                                    miniMap.refresh()
                                }
                            }
                        }

                        // Mini-map title
                        Text {
                            anchors.top: parent.top
                            anchors.left: parent.left
                            anchors.margins: 5
                            text: "Mini Map"
                            font.bold: true
                            font.pixelSize: 12
                            color: "#333333"
                        }

                        // Click to expand
                        MouseArea {
                            anchors.fill: parent
                            onClicked: {
                                stackView.push(map)
                            }
                            cursorShape: Qt.PointingHandCursor
                        }

                        // Expand icon
                        Text {
                            anchors.top: parent.top
                            anchors.right: parent.right
                            anchors.margins: 5
                            text: "🔍"
                            font.pixelSize: 16
                            color: "#666666"
                        }
                    }
                }
            }
        }
    }

    Component {
        id: map

        Page {
            title: "Map Details"

            ColumnLayout {
                anchors.fill: parent
                spacing: 10

                RowLayout {
                    spacing: 20

                    Text {
                        text: "Map Details"
                        font.pointSize: 20
                        Layout.leftMargin: 10
                        Layout.topMargin: 5
                    }

                    Button {
                        text: "Back to Camera Feed"
                        onClicked: {
                            stackView.replace(camera)
                        }
                        Layout.alignment: Qt.AlignVCenter
                    }

                    Button {
                        text: "Remote Control"
                        onClicked: {
                            stackView.push(remoteControl)
                        }
                        Layout.alignment: Qt.AlignVCenter
                    }

                    Button {
                        text: "Thumbstick Control"
                        onClicked: {
                            stackView.push(thumbstickControl)
                        }
                        Layout.alignment: Qt.AlignVCenter
                    }
                }

                Rectangle { //Full-size map view
                    color: "#F0E4D3"
                    Layout.fillWidth: true
                    Layout.minimumWidth: 300
                    Layout.preferredWidth: 800
                    Layout.minimumHeight: 150
                    Layout.preferredHeight: 400
                    Layout.maximumHeight: 400

                    // Full terrain map
                    TopographicalMapView {
                        id: fullMap
                        anchors.fill: parent
                        anchors.margins: 2

                        showConnections: true
                        showOptimalPath: true
                        optimalPath: globalOptimalPath // Bind to global path

                        // Initialize pathfinding engine with map data
                        Component.onCompleted: {
                            initializePathfindingEngineLocal()
                        }

                        // Watch for changes in globalOptimalPath and refresh
                        Connections {
                            target: application
                            function onGlobalOptimalPathChanged() {
                                fullMap.refresh()
                            }
                        }

                        function initializePathfindingEngineLocal() {
                            var nodeArray = []
                            for (var i = 0; i < fullMap.nodeModel.count; i++) {
                                var node = fullMap.nodeModel.get(i)
                                nodeArray.push({
                                    elementId: node.elementId,
                                    x: node.x,
                                    y: node.y,
                                    elevation: node.elevation,
                                    type: node.type,
                                    points: node.points || 0
                                })
                            }

                            pathfindingEngine.setNodes(nodeArray)

                            var connectionMap = {}
                            var connections = fullMap.nodeConnections
                            for (var nodeId in connections) {
                                var nodeConnections = connections[nodeId]
                                var connectionArray = []

                                for (var j = 0; j < nodeConnections.length; j++) {
                                    var conn = nodeConnections[j]
                                    if (conn.targetIndex < fullMap.nodeModel.count) {
                                        var targetNode = fullMap.nodeModel.get(conn.targetIndex)
                                        connectionArray.push({
                                            targetId: targetNode.elementId,
                                            cost: conn.cost,
                                            distance: conn.distance,
                                            targetIndex: conn.targetIndex
                                        })
                                    }
                                }
                                connectionMap[nodeId] = connectionArray
                            }

                            pathfindingEngine.setConnections(connectionMap)
                            console.log("Pathfinding engine initialized")
                        }

                    }
                }

                // Replace the existing control buttons RowLayout in Main.qml with this:

                RowLayout {
                    Layout.alignment: Qt.AlignHCenter
                    spacing: 10

                    Button {
                        text: "Optimal Ball Collection\n(8 balls max)"
                        onClicked: {
                            // Find optimal route collecting up to 8 balls and returning to release
                            var optimalRoute = pathfindingEngine.findOptimalBallCollectionRoute("start_a", "release", 8)
                            if (optimalRoute.length > 0) {
                                globalOptimalPath = optimalRoute
                                fullMap.refresh()

                                // Calculate total points
                                var totalPoints = 0
                                for (var i = 0; i < optimalRoute.length; i++) {
                                    if (optimalRoute[i].points) {
                                        totalPoints += optimalRoute[i].points
                                    }
                                }

                                console.log("Optimal collection route found with", optimalRoute.length, "nodes")
                                console.log("Total points:", totalPoints)
                                pathStatusText.text = "Route: " + optimalRoute.length + " nodes, " + totalPoints + " points"
                            } else {
                                console.log("No optimal collection route found")
                                pathStatusText.text = "No route found"
                            }
                        }
                    }

                    Button {
                        text: "High Value Route\n(Priority targets)"
                        onClicked: {
                            // Find route focusing on high-value targets only
                            var highValueNodes = [
                                "b16", "b17", // Star balls (40 points each)
                                "comm_tow"    // Communication tower (60 points)
                            ]

                            var optimalRoute = pathfindingEngine.findOptimalCollectionRoute("start_a", highValueNodes)
                            if (optimalRoute.length > 0) {
                                // Add release area to the end
                                var releaseNode = fullMap.getNodeByElementId("release")
                                if (releaseNode) {
                                    optimalRoute.push(releaseNode)
                                }

                                globalOptimalPath = optimalRoute
                                fullMap.refresh()

                                var totalPoints = 0
                                for (var i = 0; i < optimalRoute.length; i++) {
                                    if (optimalRoute[i].points) {
                                        totalPoints += optimalRoute[i].points
                                    }
                                }

                                console.log("High value route found with", optimalRoute.length, "nodes")
                                console.log("Total points:", totalPoints)
                                pathStatusText.text = "Route: " + optimalRoute.length + " nodes, " + totalPoints + " points"
                            } else {
                                console.log("No high value route found")
                                pathStatusText.text = "No route found"
                            }
                        }
                    }

                    Button {
                        text: "Start B Route\n(Alternative start)"
                        onClicked: {
                            // Find optimal route from start_b
                            var optimalRoute = pathfindingEngine.findOptimalBallCollectionRoute("start_b", "release", 8)
                            if (optimalRoute.length > 0) {
                                globalOptimalPath = optimalRoute
                                fullMap.refresh()

                                var totalPoints = 0
                                for (var i = 0; i < optimalRoute.length; i++) {
                                    if (optimalRoute[i].points) {
                                        totalPoints += optimalRoute[i].points
                                    }
                                }

                                console.log("Start B route found with", optimalRoute.length, "nodes")
                                console.log("Total points:", totalPoints)
                                pathStatusText.text = "Route: " + optimalRoute.length + " nodes, " + totalPoints + " points"
                            } else {
                                console.log("No route found from start B")
                                pathStatusText.text = "No route found"
                            }
                        }
                    }

                    Button {
                        text: "Clear Path"
                        onClicked: {
                            globalOptimalPath = []
                            pathfindingEngine.clearPath()
                            fullMap.refresh()
                            pathStatusText.text = "Path Status: None"
                            console.log("Path cleared")
                        }
                    }
                }

                // Update the status row to show more detailed information:
                RowLayout {
                    Layout.alignment: Qt.AlignHCenter
                    spacing: 20

                    Text {
                        text: "Path Length: " + globalOptimalPath.length + " nodes"
                        font.pixelSize: 12
                        color: "#666666"
                    }

                    Text {
                        id: pathStatusText
                        text: globalOptimalPath.length > 0 ? "Path Status: Active" : "Path Status: None"
                        font.pixelSize: 12
                        color: globalOptimalPath.length > 0 ? "#2ecc71" : "#e74c3c"
                    }
                }
            }
        }
    }

    Component {
        id: remoteControl

        Page {
            title: "Remote Control"

            ColumnLayout {
                anchors.fill: parent
                spacing: 10

                RowLayout {
                    spacing: 20

                    Text {
                        text: "Remote Control"
                        font.pointSize: 20
                        Layout.leftMargin: 10
                        Layout.topMargin: 5
                    }

                    Button {
                        text: "Back to Camera Feed"
                        onClicked: {
                            stackView.replace(camera)
                        }
                        Layout.alignment: Qt.AlignVCenter
                    }

                    Button {
                        text: "Back to Map View"
                        onClicked: {
                            stackView.replace(map)
                        }
                        Layout.alignment: Qt.AlignVCenter
                    }

                    Button {
                        text: "Thumbstick Control"
                        onClicked: {
                            stackView.push(thumbstickControl)
                        }
                        Layout.alignment: Qt.AlignVCenter
                    }

                }

                Rectangle {
                    width: 400
                    height: 600
                    Layout.alignment: Qt.AlignHCenter
                    gradient: Gradient {
                        GradientStop { position: 0.0; color: "#323232" }
                        GradientStop { position: 1.0; color: "#212121" }
                    }

                    ColumnLayout {
                        anchors.fill: parent
                        anchors.margins: 20
                        spacing: 20

                        // Header with connection status
                        Rectangle {
                            Layout.fillWidth: true
                            Layout.preferredHeight: 60
                            color: carController.isConnected ? "#27AE60" : "#E74C3C"
                            radius: 10

                            RowLayout {
                                anchors.centerIn: parent
                                spacing: 10

                                // Connection indicator
                                Rectangle {
                                    width: 12
                                    height: 12
                                    radius: 6
                                    color: carController.isConnected ? "#2ECC71" : "#F39C12"

                                    // Blinking animation when disconnected
                                    SequentialAnimation on opacity {
                                        running: !carController.isConnected
                                        loops: Animation.Infinite
                                        NumberAnimation { to: 0.2; duration: 500 }
                                        NumberAnimation { to: 1.0; duration: 500 }
                                    }
                                }

                                Text {
                                    text: carController.isConnected ? "Connected to Car" : "Disconnected"
                                    color: "white"
                                    font.pixelSize: 16
                                    font.bold: true
                                }
                            }
                        }

                        // Current direction display
                        Rectangle {
                            Layout.fillWidth: true
                            Layout.preferredHeight: 40
                            color: "#3498DB"
                            radius: 8

                            Text {
                                anchors.centerIn: parent
                                text: "Current Direction: " + carController.currentDirection.toUpperCase()
                                color: "white"
                                font.pixelSize: 14
                                font.bold: true
                            }
                        }

                        // Speed controls
                        GroupBox {
                            Layout.fillWidth: true
                            title: "Speed Control"

                            ColumnLayout {
                                anchors.fill: parent
                                spacing: 15

                                // Single speed control
                                RowLayout {
                                    spacing: 10

                                    Text {
                                        text: "Motor Speed:"
                                        color: "white"
                                        font.pixelSize: 14
                                        Layout.preferredWidth: 100
                                    }

                                    Slider {
                                        id: speedSlider
                                        Layout.fillWidth: true
                                        from: 0
                                        to: 255
                                        value: carController.speed
                                        stepSize: 1

                                        onValueChanged: {
                                            carController.speed = value
                                        }
                                    }

                                    Text {
                                        text: speedSlider.value.toFixed(0)
                                        color: "white"
                                        font.pixelSize: 14
                                        Layout.preferredWidth: 40
                                    }
                                }
                            }
                        }

                        // Directional controls in cross pattern
                        Item {
                            Layout.fillWidth: true
                            Layout.fillHeight: true

                            // Forward button
                            Button {
                                id: forwardBtn
                                width: 80
                                height: 80
                                anchors.horizontalCenter: parent.horizontalCenter
                                anchors.top: parent.top
                                anchors.topMargin: 20

                                text: "↑\nFORWARD"
                                font.pixelSize: 12
                                font.bold: true


                                background: Rectangle {
                                    color: forwardBtn.pressed ? "#424874" : "#DCD6F7"
                                    radius: 10
                                    border.width: 2
                                    border.color: "#424874"
                                }

                                onClicked: carController.moveForward()
                            }

                            // Left button
                            Button {
                                id: leftBtn
                                width: 80
                                height: 80
                                anchors.verticalCenter: parent.verticalCenter
                                anchors.left: parent.left
                                anchors.leftMargin: 20

                                text: "←\nLEFT"
                                font.pixelSize: 12
                                font.bold: true

                                background: Rectangle {
                                    color: leftBtn.pressed ? "#71C9CE" : "#CBF1F5"
                                    radius: 10
                                    border.width: 2
                                    border.color: "#71C9CE"
                                }

                                onClicked: carController.turnLeft()
                            }

                            // Right button
                            Button {
                                id: rightBtn
                                width: 80
                                height: 80
                                anchors.verticalCenter: parent.verticalCenter
                                anchors.right: parent.right
                                anchors.rightMargin: 20

                                text: "→\nRIGHT"
                                font.pixelSize: 12
                                font.bold: true

                                background: Rectangle {
                                    color: rightBtn.pressed ? "#F2BED1" : "#F8E8EE"
                                    radius: 10
                                    border.width: 2
                                    border.color: "#F2BED1"
                                }

                                onClicked: carController.turnRight()
                            }

                            // Backward button
                            Button {
                                id: backwardBtn
                                width: 80
                                height: 80
                                anchors.horizontalCenter: parent.horizontalCenter
                                anchors.bottom: parent.bottom
                                anchors.bottomMargin: 20

                                text: "↓\nBACKWARD"
                                font.pixelSize: 12
                                font.bold: true

                                background: Rectangle {
                                    color: backwardBtn.pressed ? "#D2DAFF" : "#EEF1FF"
                                    radius: 10
                                    border.width: 2
                                    border.color: "#D2DAFF"
                                }

                                onClicked: carController.moveBackward()
                            }

                            // Center stop button
                            Button {
                                id: stopBtn
                                width: 80
                                height: 40
                                anchors.centerIn: parent

                                text: "STOP"
                                font.pixelSize: 14
                                font.bold: true

                                background: Rectangle {
                                    color: stopBtn.pressed ? "#E74C3C" : "#ff9999"
                                    radius: 10
                                    border.width: 2
                                    border.color: "#922B21"
                                }

                                onClicked: carController.stopCar()
                            }
                        }

                        // Special function buttons
                        RowLayout {
                            Layout.fillWidth: true
                            spacing: 10

                            Button {
                                Layout.fillWidth: true
                                text: "Back & Forth"
                                font.bold: true

                                background: Rectangle {
                                    color: parent.pressed ? "#ECE2E1" : "#ECE2E1"
                                    radius: 8
                                    border.width: 1
                                    border.color: "#ECE2E1"
                                }

                                onClicked: carController.backAndForth()
                            }

                            Button {
                                Layout.fillWidth: true
                                text: "EMERGENCY STOP"
                                font.bold: true

                                background: Rectangle {
                                    color: parent.pressed ? "#D3E0DC" : "#D3E0DC"
                                    radius: 8
                                    border.width: 1
                                    border.color: "#D3E0DC"
                                }

                                onClicked: carController.emergencyStop()
                            }
                        }
                    }

                    Connections {
                        target: carController

                        function onRequestSent(direction) {
                            // Visual feedback when request is sent
                            console.log("Request sent for direction:", direction)
                        }

                        function onRequestFailed(error) {
                            // Handle request failures
                            console.log("Request failed:", error)
                        }
                    }
                }
            }
        }
    }

    Component {
        id: thumbstickControl

        Page {
            title: "Thumbstick Control"

            ColumnLayout {
                anchors.fill: parent
                spacing: 15

                // Navigation buttons
                RowLayout {
                    spacing: 20

                    Text {
                        text: "Thumbstick Control"
                        font.pointSize: 20
                        Layout.leftMargin: 10
                        Layout.topMargin: 5
                    }

                    Button {
                        text: "Back to Camera Feed"
                        onClicked: {
                            stackView.replace(camera)
                        }
                        Layout.alignment: Qt.AlignVCenter
                    }

                    Button {
                        text: "Map View"
                        onClicked: {
                            stackView.replace(map)
                        }
                        Layout.alignment: Qt.AlignVCenter
                    }

                    Button {
                        text: "Remote Control"
                        onClicked: {
                            stackView.replace(remoteControl)
                        }
                        Layout.alignment: Qt.AlignVCenter
                    }
                }

                // Main control area
                Rectangle {
                    width: 600
                    height: 600
                    color: "#2C3E50"
                    Layout.alignment: Qt.AlignHCenter
                    radius: 10

                    ColumnLayout {
                        anchors.fill: parent
                        anchors.margins: 20
                        spacing: 20

                        // Connection Status Header
                        Rectangle {
                            Layout.fillWidth: true
                            Layout.preferredHeight: 60
                            color: thumbstickController.isConnected ? "#27AE60" : "#E74C3C"
                            radius: 10

                            RowLayout {
                                anchors.centerIn: parent
                                spacing: 10

                                Rectangle {
                                    width: 12
                                    height: 12
                                    radius: 6
                                    color: thumbstickController.isConnected ? "#2ECC71" : "#F39C12"

                                    SequentialAnimation on opacity {
                                        running: !thumbstickController.isConnected
                                        loops: Animation.Infinite
                                        NumberAnimation { to: 0.2; duration: 500 }
                                        NumberAnimation { to: 1.0; duration: 500 }
                                    }
                                }

                                Text {
                                    text: thumbstickController.isConnected ? "Serial Connected" : "Serial Disconnected"
                                    color: "white"
                                    font.pixelSize: 16
                                    font.bold: true
                                }
                            }
                        }

                        // Configuration Section
                        GroupBox {
                            Layout.fillWidth: true

                            ColumnLayout {
                                anchors.fill: parent
                                spacing: 15

                                // Serial port selection
                                RowLayout {
                                    spacing: 10

                                    Text {
                                        text: "Serial Port:"
                                        color: "white"
                                        font.pixelSize: 14
                                        Layout.preferredWidth: 100
                                    }

                                    ComboBox {
                                        id: serialPortCombo
                                        Layout.preferredWidth: 200
                                        model: thumbstickController.getAvailableSerialPorts()
                                        currentIndex: {
                                            var ports = thumbstickController.getAvailableSerialPorts()
                                            return Math.max(0, ports.indexOf(thumbstickController.serialPort))
                                        }
                                        onCurrentTextChanged: {
                                            if (currentText) {
                                                thumbstickController.serialPort = currentText
                                            }
                                        }
                                    }

                                    Button {
                                        text: "Refresh"
                                        onClicked: {
                                            serialPortCombo.model = thumbstickController.getAvailableSerialPorts()
                                        }
                                    }
                                }

                                // Car URL configuration
                                RowLayout {
                                    spacing: 10

                                    Text {
                                        text: "Car URL:"
                                        color: "white"
                                        font.pixelSize: 14
                                        Layout.preferredWidth: 100
                                    }

                                    TextField {
                                        id: carUrlField
                                        Layout.preferredWidth: 200
                                        text: thumbstickController.carUrl
                                        placeholderText: "http://192.168.4.1"
                                        onTextChanged: {
                                            thumbstickController.carUrl = text
                                        }
                                    }
                                }

                                // Control buttons
                                RowLayout {
                                    spacing: 10

                                    Button {
                                        text: thumbstickController.isConnected ? "Disconnect" : "Connect"
                                        onClicked: {
                                            if (thumbstickController.isConnected) {
                                                thumbstickController.disconnectSerial()
                                            } else {
                                                thumbstickController.connectSerial()
                                            }
                                        }
                                    }

                                    CheckBox {
                                        text: "Enable Thumbstick Control"
                                        checked: thumbstickController.thumbstickEnabled
                                        enabled: thumbstickController.isConnected
                                        onCheckedChanged: {
                                            thumbstickController.thumbstickEnabled = checked
                                        }
                                    }
                                }

                                // Manual Gripper Control (NEW SECTION)
                                RowLayout {
                                    spacing: 10

                                    Text {
                                        text: "Manual Gripper:"
                                        color: "white"
                                        font.pixelSize: 14
                                        Layout.preferredWidth: 120
                                    }

                                    Button {
                                        text: "Open Gripper"
                                        enabled: thumbstickController.isConnected
                                        background: Rectangle {
                                            color: parent.pressed ? "#27AE60" : "#2ECC71"
                                            radius: 5
                                            border.width: 1
                                            border.color: "#2980B9"
                                        }
                                        onClicked: {
                                            thumbstickController.sendGripperCommand("open")
                                        }
                                    }

                                    Button {
                                        text: "Close Gripper"
                                        enabled: thumbstickController.isConnected
                                        background: Rectangle {
                                            color: parent.pressed ? "#E74C3C" : "#EC7063"
                                            radius: 5
                                            border.width: 1
                                            border.color: "#E67E22"
                                        }
                                        onClicked: {
                                            thumbstickController.sendGripperCommand("close")
                                        }
                                    }
                                }

                                // NEW DUMPER CONTROL SECTION - ADD THIS AFTER THE GRIPPER CONTROL
                                RowLayout {
                                    spacing: 10

                                    Text {
                                        text: "Manual Dumper:"
                                        color: "white"
                                        font.pixelSize: 14
                                        Layout.preferredWidth: 120
                                    }

                                    Button {
                                        text: "Open Dumper"
                                        enabled: thumbstickController.isConnected
                                        background: Rectangle {
                                            color: parent.pressed ? "#27AE60" : "#2ECC71"
                                            radius: 5
                                            border.width: 1
                                            border.color: "#1E8449"
                                        }
                                        onClicked: {
                                            thumbstickController.sendDumperCommand("dumperOpen")
                                        }
                                    }

                                    Button {
                                        text: "Close Dumper"
                                        enabled: thumbstickController.isConnected
                                        background: Rectangle {
                                            color: parent.pressed ? "#E74C3C" : "#EC7063"
                                            radius: 5
                                            border.width: 1
                                            border.color: "#C0392B"
                                        }
                                        onClicked: {
                                            thumbstickController.sendDumperCommand("dumperClose")
                                        }
                                    }
                                }

                            }
                        }

                        // Real-time Data Display
                        RowLayout {
                            Layout.fillWidth: true
                            spacing: 20

                            // Motor Control Data
                            GroupBox {
                                Layout.fillWidth: true

                                ColumnLayout {
                                    spacing: 8

                                    Text {
                                        text: "Raw X: " + thumbstickController.motorRawX
                                        color: "white"
                                        font.pixelSize: 12
                                    }
                                    Text {
                                        text: "Raw Y: " + thumbstickController.motorRawY
                                        color: "white"
                                        font.pixelSize: 12
                                    }
                                    Text {
                                        text: "Direction: " + thumbstickController.motorDirection.toUpperCase()
                                        color: thumbstickController.motorDirection === "stop" ? "#E74C3C" : "#2ECC71"
                                        font.pixelSize: 12
                                        font.bold: true
                                    }
                                    Text {
                                        text: "Speed: " + thumbstickController.motorSpeed
                                        color: "white"
                                        font.pixelSize: 12
                                    }
                                }
                            }

                            // Arm Control Data
                            GroupBox {
                                Layout.fillWidth: true

                                ColumnLayout {
                                    spacing: 8

                                    Text {
                                        text: "Raw X: " + thumbstickController.armRawX
                                        color: "white"
                                        font.pixelSize: 12
                                    }
                                    Text {
                                        text: "Raw Y: " + thumbstickController.armRawY
                                        color: "white"
                                        font.pixelSize: 12
                                    }
                                    Text {
                                        text: "Command: " + thumbstickController.armCommand.toUpperCase()
                                        color: thumbstickController.armCommand === "stop" ? "#E74C3C" : "#2ECC71"
                                        font.pixelSize: 12
                                        font.bold: true
                                    }
                                    Text {
                                        text: "Gripper: " + thumbstickController.buttonState
                                        color: thumbstickController.buttonState === "CLOSE" ? "#F39C12" : "#3498DB"
                                        font.pixelSize: 12
                                        font.bold: true
                                    }
                                }
                            }
                        }

                        // Status and Debug Info
                        GroupBox {
                            Layout.fillWidth: true
                            Layout.preferredHeight: 120
                            title: "Debug Info"

                            ScrollView {
                                anchors.fill: parent

                                TextArea {
                                    id: debugOutput
                                    readOnly: true
                                    wrapMode: TextArea.Wrap
                                    color: "white"
                                    font.pixelSize: 10
                                    text: "Waiting for serial data..."

                                    function addDebugLine(line) {
                                        text = line + "\n" + text
                                        // Keep only last 10 lines
                                        var lines = text.split("\n")
                                        if (lines.length > 10) {
                                            text = lines.slice(0, 10).join("\n")
                                        }
                                    }
                                }
                            }
                        }
                    }

                    // Connections for handling thumbstick events
                    Connections {
                        target: thumbstickController

                        function onSerialDataReceived(data) {
                            debugOutput.addDebugLine("RX: " + data)
                        }

                        function onHttpRequestSent(endpoint, direction, speed) {
                            debugOutput.addDebugLine("HTTP → " + endpoint + ": " + direction + " (speed: " + speed + ")")
                        }

                        function onHttpRequestFailed(endpoint, error) {
                            debugOutput.addDebugLine("HTTP ERROR " + endpoint + ": " + error)
                        }

                        function onMotorControlReceived(direction, speed) {
                            console.log("Motor control:", direction, "speed:", speed)
                        }

                        function onArmControlReceived(command) {
                            console.log("Arm command:", command)
                        }

                        function onGripperControlReceived(state) {
                            console.log("Gripper:", state)
                        }
                    }
                }
            }
        }
    }
}
