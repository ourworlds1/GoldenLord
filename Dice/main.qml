import QtQuick 2.12

Item {
    id : www
    visible: true
    width: 800
    height: 640

    property real diceStartX : 100 -15
    property real wCenterY : www.height /2
    property real wEndX : www.width
    property bool rounding : false
    property real round : 1

    Rectangle{
        anchors.fill: parent
        color : "white"
    }


    Canvas{
        id: pathPaint
        anchors.fill: parent
        width: www.width
        height: www.height
        z:1
        property real startX : 0
        property real startY : 0
        property real centerY : www.height / 2
        property real lastX : 100
        property real lastY : 640
        onPaint: {
            var ctx = getContext('2d')
            ctx.lineWidth = 5
            ctx.strokeStyle = "black"
            ctx.beginPath()
            ctx.moveTo(lastX, startY) // 100, 0
            ctx.lineTo(lastX, lastY) // 100, 640 까지 Line 그리기
            // 100, 0 -> 100, 640 까지 라인 그리기
            ctx.moveTo(lastX, centerY) // 100 , 320 로 이동
            ctx.lineTo(www.width,centerY)
            ctx.stroke()
        }
    }

    Canvas{  //Dice 판
        id: rectPaint
        anchors.fill: parent
        width: www.width
        height: www.height
        z:1
        property real centerY : www.height / 2
        property real startX : 150
        property real startY : centerY+30
        property real lastX : www.width - startX - 50
        property real lastY : centerY - 60
        property real endY : startY + lastY
        property real endX: startX + lastX
        property real rectWidth : lastX - startX
        property  real rectHeight: (centerY - 60 )
        onPaint: {
            console.log(rectWidth)
            var ctx = getContext('2d')
            ctx.lineWidth = 5
            ctx.strokeStyle = "black"
            ctx.beginPath()
            ctx.moveTo(startX, startY) // 100, 0
            ctx.rect(startX,startY,lastX,lastY)
            for(var i=1; i<5; i++)
            {
                ctx.moveTo( startX + lastX/5*i  , startY)
                ctx.lineTo(startX + lastX/5*i, endY)
            }
            for (var i=1; i<3; i++)
            {
                ctx.moveTo( startX  , startY + rectHeight / 3 * i)
                ctx.lineTo( endX, startY + rectHeight / 3 * i)
            }
            ctx.stroke()
        }
    }

    property real monsterCX : monsterD.x + monsterD.width/2
    property real monsterCY : monsterD.y + monsterD.height / 2

    Rectangle{
        id : monsterD
        x : diceStartX
        y : www.height
        width: 30
        height: 30
        color : "red"
        Component.onCompleted: moveTimer.start()
        property bool roundStart : false
        onRoundStartChanged: {
            if(roundStart === true)
            {
                roundStart = false
                monsterD.x = diceStartX
                monsterD.y = www.height
                moveTimer.start()
            }
        }
        z:4
        Timer{
            id :moveTimer
            interval: 10
            repeat: true
            onTriggered: {
                rounding = true
                if(monsterD.y != wCenterY-15)
                    monsterD.y--
                else
                    monsterD.x++

                if(monsterD.x === www.wEndX)
                {
                    stop()
                    rounding = false
                }
            }
        }
    }

    function reset() {
        monsterD.roundStart = true
    }

    onRoundingChanged: {
        if(rounding === false)
        {
            round++
            breakTimer.start()
        }
    }

    Timer{
        id : breakTimer
        interval: 1000
        onTriggered: reset()
    }

    AttackLine {
        id : firAttackLine
        anchors.fill: parent
        y : www.height /2
        width: www.width
        height: www.height /2
        startX : 150 + 45
        startY :  350 + 260 / 6
        destX : monsterCX
        destY : monsterCY
    }

    onMonsterCXChanged: {
        firAttackLine.reqP()
    }
    onMonsterCYChanged: {
        firAttackLine.reqP()
    }

    Text {
        id: roundText
        text: round.toString()
        x : 45
        y : wCenterY - 15
        color : "red"
        font.pixelSize: 30
        font.bold: true
    }

    Component.onCompleted: pathPaint.requestPaint()

}
