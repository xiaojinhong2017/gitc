React优点

1、React速度很快：它并不直接对DOM进行操作，引入了一个叫做虚拟DOM的概念，安插在javascript逻辑和实际的DOM之间，性能好。

2、跨浏览器兼容：虚拟DOM帮助我们解决了跨浏览器问题，它为我们提供了标准化的API，甚至在IE8中都是没问题的。

3、一切都是component：代码更加模块化，重用代码更容易，可维护性高。

4、单向数据流：Flux是一个用于在JavaScript应用中创建单向数据层的架构，它随着React视图库的开发而被Facebook概念化。

5、同构、纯粹的javascript：因为搜索引擎的爬虫程序依赖的是服务端响应而不是JavaScript的执行，预渲染你的应用有助于搜索引擎优化。



纯粹的JavaScript

现代Web应用程序与传统的Web应用有着不同的工作方式。
例如，视图层的更新需要通过用户交互而不需要请求服务器。因此视图和控制器非常依赖彼此。
许多框架使用Handlebars或Mustache等模板引擎来处理视图层。但React相信视图和控制器应该相互依存在一起而不是使用第三方模板引擎，而且，最重要的是，它是纯粹的JavaScript程序。
同构:单页面js应用程序的最大缺陷在于对搜索引擎的索引有很大限制。React对此有了解决方案。
React可以在服务器上预渲染应用再发送到客户端。它可以从预渲染的静态内容中恢复一样的记录到动态应用程序中。
因为搜索引擎的爬虫程序依赖的是服务端响应而不是JavaScript的执行，预渲染你的应用有助于搜索引擎优化。

6、React与其他框架/库兼容性好：比如使用RequireJS来加载和打包，而Browserify和Webpack适用于构建大型应用。它们使得那些艰难的任务不再让人望而生畏。


React组件的更新原理


React的生命周期
实例化

首次实例化

    getDefaultProps
    getInitialState
    componentWillMount
    render
    componentDidMount

实例化完成后的更新

    getInitialState
    componentWillMount
    render
    componentDidMount

存在期

组件已存在时的状态改变

    componentWillReceiveProps
    shouldComponentUpdate
    componentWillUpdate
    render
    componentDidUpdate

销毁&清理期

    componentWillUnmount


props与state的区别

需要理解的是，props是一个父组件传递给子组件的数据流，这个数据流可以一直传递到子孙组件。而state代表的是一个组件内部自身的状态（可以是父组件、子孙组件）。
改变一个组件自身状态，从语义上来说，就是这个组件内部已经发生变化，有可能需要对此组件以及组件所包含的子孙组件进行重渲染。
而props是父组件传递的参数，可以被用于显示内容，或者用于此组件自身状态的设置（部分props可以用来设置组件的state），不仅仅是组件内部state改变才会导致重渲染，父组件传递的props发生变化，也会执行。

既然两者的变化都有可能导致组件重渲染，所以只有理解pros与state的意义，才能很好地决定到底什么时候用props或state。


官方指导有说，props放初始化数据，一直不变的，state就是放要变的。


State 应该包括那些可能被组件的事件处理器改变并触发用户界面更新的数据,因为组件本身不能修改自己的 props。
