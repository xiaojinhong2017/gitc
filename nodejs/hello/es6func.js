// var  id =  21;
function foo(){
  setTimeout(()=>{
    console.log('id:',this.id);
  },100);
}
// foo.call({'id':'aaa'});
// foo();
var f = v => v;
console.log(f(1));
var a = () => 5;
console.log(a());

var sum = (num1 , num2) => num1 + num2 ;
console.log(sum(2,3));


//如果箭头函数的代码部分多于一条语句，就要使用大括号将它们括起来，并且使用return语句返回
var  sum = (num1,num2) => {return num1 + num2;}

//由于大括号被解释为代码块，为了区分，如果箭头函数直接返回一个对象，必须在对象外面加上括号

var getTempItem = id => ({id:id,name:"Temp"});
console.log(getTempItem(1));

//箭头函数可以与变量结构结合使用
const full = ({ first,last }) => first + ' ' + last;
//等价于function full(person){
//return person.first + ' ' + person.last;
//}

//箭头函数使得表达更加简洁。
const isEven = n => n % 2 == 0;
console.log(isEven(10));
const square = n => n * n;
console.log(square(100));

//rest 参数与箭头函数结合的例子
const numbers = (...nums) =>  nums;
numbers(1,2,3,4,5);//[1,2,3,4,5]
const headAndTail = (head, ...tail) => [head,tail];
head(1,2,3,4,5);//[1,[2,3,4,5]]
