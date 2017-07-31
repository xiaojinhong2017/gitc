{
  let a = 10;
  var b = 1;
console.log(a);
}
console.log(b);
for(let i = 0; i < 10 ; i ++){
  //
}
console.log(i);//undefine


var a = [];
for(var i = 0 ; i < 10; i ++){
  a[i] = function(){
    console.log(i);
  };
}
a[6]();//10

var a = [] ;
for(let i = 0; i < 10; i ++){
  a[i] = function(){
    console.log(i);
  }
}
a[6]();//6


for(let i = 0; i < 3; i ++){
  let i = 'abc'
  console.log(i);
}
