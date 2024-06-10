# 注解的定义

1. 注解是一种元数据形式。即注解是属于java的一种数据类型，和类、接口、数组、枚举类似。
2. 注解用来修饰，类、方法、变量、参数、包。
3. 注解不会对所修饰的代码产生直接的影响。

# 注解的使用范围

1.**为编译器提供信息** - 注解能被编译器检测到错误或抑制警告。

2.**编译时和部署时的处理** - 软件工具能处理注解信息从而生成代码，XML文件等等

3.**运行时的处理** - 有些注解在运行时能被检测到。

# 自定义注解的步骤

​    ![0](https://note.youdao.com/yws/res/4499/WEBRESOURCE309cabf0e0905e39510485e4ae237718)

# 基本语法

```java
public @interface CherryAnnotation {
    public String name();
    int age() default 18;
    int[] array();
}
```

​              

1.在自定义注解中，其实现部分**只能定义**一个东西：**注解类型元素（annotation type element）**

2.定义注解类型元素时需要注意如下几点：

​    ①访问修饰符**必须为public**，不写默认为public；

​    ②该元素的类型只能是**基本数据类型**、**String**、**Class**、**枚举类型**、**注解类型**（体现了注解的嵌套效果）以及**上述类型的一维数组**；

​    ③该元素的名称一般定义为名词，如果注解中只有一个元素，请把名字起为value（后面使用会带来便利操作）；

​    ④()不是定义方法参数的地方，也不能在括号中定义任何参数，仅仅只是一个特殊的语法；

​    ⑤default代表默认值，值必须和第2点定义的类型一致；

   ⑥ **如果没有默认值，代表后续使用注解时必须给该类型元素赋值**。

3.注解在定义好了以后，**使用的时候操作元素类型像在操作属性，解析的时候操作元素类型像在操作方法**。

# 五、元注解

元注解：**专门修饰注解的注解**

**@Taeget		@Retention		@Documented		@Inherited**

**1. @Target**

自定义注解能够被应用在哪些Java元素上面

```java
@Target({ElementType.TYPE,ElementType.METHOD})
public @interface CherryAnnotation {
    public String name();
    int age() default 18;
    int[] array();
}
```

​          

**摘自源码：**

```java
package java.lang.annotation;
public enum ElementType {
    /** Class, interface (including annotation type), or enum declaration */
    TYPE,

    /** Field declaration (includes enum constants) */
    FIELD,

    /** Method declaration */
    METHOD,

    /** Formal parameter declaration */
    PARAMETER,

    /** Constructor declaration */
    CONSTRUCTOR,

    /** Local variable declaration */
    LOCAL_VARIABLE,

    /** Annotation type declaration */
    ANNOTATION_TYPE,

    /** Package declaration */
    PACKAGE,

    /**
     * Type parameter declaration
     *
     * @since 1.8
     */
    TYPE_PARAMETER,

    /**
     * Use of a type
     *
     * @since 1.8
     */
    TYPE_USE
}       
```

**2. @Retention**

持久力、保持力。

 注解的生命周期有三个阶段：1、Java源文件阶段；2、编译到class文件阶段；3、运行期阶段

**摘自源码：**

```java
package java.lang.annotation;
public enum RetentionPolicy {
    /**
     * Annotations are to be discarded by the compiler.
     */
    SOURCE,

    /**
     * Annotations are to be recorded in the class file by the compiler
     * but need not be retained by the VM at run time.  This is the default
     * behavior.
     */
    CLASS,

    /**
     * Annotations are to be recorded in the class file by the compiler and
     * retained by the VM at run time, so they may be read reflectively.
     *
     * @see java.lang.reflect.AnnotatedElement
     */
    RUNTIME
}
```

​            

RetentionPolicy.SOURCE，限定在Java源文件中，不参与编译，不会在运行期起作用；这个注解就和一个注释是一样的效果，只能被阅读Java文件的人看到

RetentionPolicy.CLASS，被编译到Class文件中，编译器可以在编译时根据注解做一些处理动作，但是运行时JVM（Java虚拟机）会忽略它，在运行期也不能读取到；

RetentionPolicy.RUNTIME，注解可以在运行期的加载阶段被加载到Class对象中。在程序运行阶段，可以通过反射得到这个注解，并通过判断是否有这个注解或这个注解中属性的值，从而执行不同的程序代码段。实际开发中的自定义注解几乎都是使用的RetentionPolicy.RUNTIME

在默认的情况下，自定义注解是使用的RetentionPolicy.CLASS。

**3. @Documented**

指定自定义注解是否能随着被定义的java文件生成到JavaDoc文档当中。

**4.  @Inherited**

指定某个自定义注解如果写在了父类的声明部分，那么子类的声明部分也能自动拥有该注解。@Inherited注解只对那些@Target被定义为**ElementType.TYPE**的自定义注解起作用。

# 五、特殊语法

**1. 特殊语法一：****@注解名**

**注解本身没有注解类型元素时，在使用注解的时候可以省略()，直接写为：****@注解名****，它和标准语法****@注解名()****等效！**

```java
@Retention(RetentionPolicy.RUNTIME)
@Target(value = {ElementType.TYPE})
@Documented
public @interface FirstAnnotation {
}
//没有注解类型元素的注解



//等效于@FirstAnnotation()
@FirstAnnotation
public class JavaBean{
	//省略实现部分
}

```

​          

**2. 特殊语法二：****@注解名(注解值)**

**注解本身只有** **1** **个注解类型元素，且命名为****value****，在使用注解的时候可以直接使用：****@注解名(注解值)****，其等效于：****@注解名(value = 注解值)**

```java
@Retention(RetentionPolicy.RUNTIME)
@Target(value = {ElementType.TYPE})
@Documented
public @interface SecondAnnotation {
	String value();
}




//等效于@ SecondAnnotation(value = "this is second annotation")
@SecondAnnotation("this is annotation")
public class JavaBean{
	//省略实现部分
}
```

​           

**3. 特殊用法三：**

**注解中的某个注解类型元素是一个****数组类型****，在使用时又出现只需要填入** **1** **个****值的情况，在使用注解时可以直接写为：****@注解名(类型名 = 类型值)****，等效标准写法：****@注解名(类型名 = {类型值})**

```java
//等效于@ ThirdAnnotation(name = {"this is third annotation"})
@ ThirdAnnotation(name = "this is third annotation")
public class JavaBean{
	//省略实现部分
}
```

​    

4. 特殊用法四：

**注解的@Target是定义为****Element.PACKAGE****时，这个注解是配置在****package-info.java****中的，而不能直接在某个类的package代码上面配置。**