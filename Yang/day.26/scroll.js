/*
功能：获得document上滚动条的滚动距离
返回值：对象
*/

function scroll(){
  if (window.offsetPageY){
    return {
      left: window.offsetPageX,
      top: window.offsetPageY
    }
  } else if (document.body.scrollTop){
    return {
      left: document.body.scrollLeft,
      top : document.body.scrollTop
    }
  } else if(document.documentElement.scrollTop) {
    return {
      left: document.documentElement.scrollLeft,
      top : document.documentElement.scrollTop
    }
  }
}
