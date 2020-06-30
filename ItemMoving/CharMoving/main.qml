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
    }
    Component.onCompleted: moveT.start()
    property int mo: 0
    property int xpm: 0
    property int xmm: 0

    property int ypm: 0
    property int ymm: 0

    property int dir : 1

    function edgecheck( ){
        if(firChar.x === 0 || firChar.y ===0 ||
                firChar.x === www.width || firChar.y === www.height)
        {
            console.log("meet edge" , dir)
            moveT.stop()
            dir = dir  * -1
            moveT.restart()
            return true
        }
        else
        {
            return false
        }
    }


    function moveTo( ){

    }

    function move() {
        mo = Math.random(3) *100 % 4
        switch(mo)
        {
        case 0:
            if(edgecheck() === false)
            {
                xmm++
                firChar.x -= 1 * dir
            }
            break;
        case 1:
            if(edgecheck() === false)
            {
                ymm++
                firChar.y -= 1 * dir
            }
            break;
        case 2:
            if(edgecheck() === false)
            {
                xpm++
                firChar.x += 1 * dir
            }
            break;
        case 3:
            if(edgecheck() === false)
            {
                ypm++
                firChar.y += 1 * dir
            }
            break;
        default:
            break;
        }

    }

    Timer{
        id :moveT
        onTriggered: move()
        interval: 500
        repeat: true
    }

}
