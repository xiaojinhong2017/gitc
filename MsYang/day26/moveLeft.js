/*
功能：进行水平运算偏移
@f, 要偏移的DOM对象
@target, 最终目的位置
@speed, number,每次的偏移量
@interval, 间隔时间
*/
function moveLeft(elem,target,speed,interval){
  //先清除可能会干扰的定时器
  clearInterval(elem.timer);
  //速度正负是由其实的位置和目标决定
  speed = target > elem.offsetLeft ? speed : -speed;

  elem.timer = setInterval(function(){
    elem.style.left = elem.offsetLeft + speed  + "px";
    if (Math.abs(elem.offsetLeft - target) <= Math.abs(speed)){
      elem.style.left = target + "px";
      clearInterval(elem.timer);
    }
  },interval);
}
