vue父子组件数据传递：prop

父向子，props；

传递静态数据

​    

const login={

​    template：`HTML标签{{title}}      {{logintitle}}      {{aa}}`，

​     data（）{//不能定义props同名的属性

​        return  {

​             loginTitle：this.title

​        }

}，

​    props:['title'，'aa'，'age']，//this.title，接收组件传递的数据

}

new Vue（{

​     el:'#app',

​     components:{

​           login，       

​     }

}）

传递动态数据

new Vue（{

​    el：''，

​    data：{

​        name：'曹操'，

​    }

}）

单向下行绑定。单向数据流。

子组件传递数据给父组件，通过父组件的事件事件。（传递父组件的事件）@事件别名

给父组件的事件处理函数起个别名@别名，传给子组件，子组件通过this.$emit（'父组件事件处理函数的别名'）来调用父组件的事件处理函数

const login={

​       template：`HTML代码   @click="test"`，

​       data（）{

​                return  {

​                       msg:"子组件"

​                 }；

​        }，

​      methods：{

​               test（）{

​                    this.$emit（'aa'，this.msg）；//可以传递对象

​               }

​       }

​     

}；

const app=new Vue（{

​        el："#app"，

​        data：{

​        }，

​        methods：{

​              findAll（param）{

​                  打印param

​              }

​         }，

​         components：{

​               login，

​          }

}）