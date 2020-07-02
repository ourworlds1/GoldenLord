import QtQuick 2.0

Item {

    property real startX : 0
    property real startY : 0
    property real destX : 0
    property real destY : 0
    signal reqP

    onReqP: attackLine.requestPaint()

    Canvas{
        id: attackLine
        anchors.fill: parent
        y : parent.y
        width: parent.width
        height: parent.height
        z:2
        property real startX : 150 + 45
        property real startY :  350 + 260 / 6
        property real destX : monsterCX
        property real destY : monsterCY
        onPaint: {
            var ctx = getContext('2d')

            ctx.reset()
            ctx.lineWidth = 5
            ctx.strokeStyle = "blue"
            ctx.beginPath()
            ctx.moveTo(startX, startY)
            ctx.lineTo( destX, destY)
            ctx.stroke()
        }
    }
}
