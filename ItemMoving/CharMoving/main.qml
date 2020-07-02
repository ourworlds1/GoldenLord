import QtQuick 2.12
//import QtQuick.Window 2.12

Item{
    id : www
    x :0
    y: 0
    visible: true
    width: 800
    height: 640

    property var map

    Rectangle{
        anchors.fill: parent
        color : "White"
    }

    Rectangle{
        id:firChar
        x : 50
        y : 50
        width : 10
        height : 10
        color : "red"
        z:5

//        onXChanged:
//            NumberAnimation {
//            target: firChar
//            property: "x"
//            duration: 50
//            easing.type: Easing.Linear
//        }
//        onYChanged:
//            NumberAnimation {
//            target: firChar
//            property: "y"
//            duration: 50
//            easing.type: Easing.Linear
//        }
    }
    Component.onCompleted: moveT.start()
    property int mo: 0
    property int moveInterval: 5
    property int xpm: 0
    property int xmm: 0

    property int ypm: 0
    property int ymm: 0

    property int xdir : 1
    property int ydir : 1

    function edgecheck( ){
        var ret = false
        if(firChar.x === 0 || firChar.x === www.width )
        {
            xdir = xdir * -1
            ret = true
        }

        if(firChar.y ===0 || firChar.y === www.height)
        {
            ret = true
            ydir = ydir * -1
        }

        return ret
    }
    property var visit : [[]]

    Canvas{
        id: pathPaint
        anchors.fill: parent
        width: www.width
        height: www.height
        z:4
        property real lastX : firChar.x
        property real lastY : firChar.y
        onPaint: {
                    var ctx = getContext('2d')
                    ctx.lineWidth = 10
                    ctx.strokeStyle = "green"
                    ctx.beginPath()
                    ctx.moveTo(lastX, lastY)
                    lastX = firChar.x
                    lastY = firChar.y
                    ctx.lineTo(lastX, lastY)
                    ctx.stroke()
                }

    }

    function move() {
        mo = Math.random() *1000 % 4
        edgecheck()
        switch(mo)
        {
        case 0:
            xmm++
            if(firChar.x - moveInterval*xdir  >= 0 && firChar.x - moveInterval*xdir <= www.width)
                firChar.x -= moveInterval * xdir
            break;
        case 1:
            ymm++
            if(firChar.y - moveInterval*ydir >= 0 && firChar.y -moveInterval *ydir <=www.height)
                firChar.y -= moveInterval * ydir
            break;
        case 2:            
            xpm++
            if(firChar.x + moveInterval*xdir >=0 && firChar.x + moveInterval*xdir <= www.width)
                firChar.x += moveInterval * xdir
            break;
        case 3:
            ypm++
            if(firChar.y + moveInterval*ydir >=0 && firChar.y + moveInterval* ydir <= www.height)
                firChar.y += moveInterval * ydir
            break;
        default:
            break;
        }
        pathPaint.requestPaint()
    }

    Timer{
        id :moveT
        onTriggered: move()
        interval: 50
        repeat: true
    }

}
