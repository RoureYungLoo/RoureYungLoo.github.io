# 01-HTML笔记

[HTML elements reference - HTML: HyperText Markup Language | MDN (mozilla.org)](https://developer.mozilla.org/en-US/docs/Web/HTML/Element)

## HTML文档结构

```html
<!DOCTYPE html>
<html>
    <head>
        
    </head>
	<body>
        
    </body>
</html>

```

## 网页标题

```html
<head>
    <title>  </title>
</head>
```

## 网页元数据

```html
<head>
    <meta charset="UTF-8" />
    <meta name="author" content=""/>
    <meta name="keywords" content=""/>
    <meta name="description" content=""/>
    <meta name="generator" content=""/>
    <meta name="revised" content=""/>
    <meta http-equiv="content-type" content="" />
    <meta http-equiv="expires" content="" />
    <meta http-equiv="refresh" content="" />
    <meta http-equiv="set-cookie" content="" />
</head>
```

## HTML5文档结构

```html
<!DOCTYPE html>
<html>
    <head>
        
    </head>
	<body>
        <header> </header>
        <nav> </nav>
        <footer> </footer>
        <section> </section>
        <article> </article>
        <aside> </aside>
    </body>
</html>
```

## 文字和段落

```html
<!DOCTYPE html>
<html>
    <head>
        
    </head>
	<body>
        <h1> </h1>
        <h2> </h2>
        <h3> </h3>
        <h4> </h4>
        <h5> </h5>
        <h6> </h6>
		<p>
        	段落<br/>换行
            水平线<hr/>
        	<b>粗体</b>
        	<i>斜体</i>
        	<ins>下划线</ins>
        	<del>中划线</del>
        	<small>小文字</small>
        	<sup>右上标</sup> <sub>右下标</sub>
        </p>
    	<pre>格式化文本</pre>
        <ruby>
        	注音<rt>zhu yin</rt>
    	</ruby>
    	<cite>标注</cite>
    <em>…</em>
    <strong>…</strong>
	<dfn>…</dfn>
	<code>…</code>
	<samp>…</samp>
	<kbd>…</kbd>
	<var>…</var>
	<blockquote>…</blockquote>
	<q>…</q>
	<address>……</address>
	<abbr>…</abbr>
    </body>
</html>
```

### 块级元素

Block，可以包含块级元素和行内元素

### 行内元素

Inline，只能包含行内元素，只能处于块级元素内

### 特3殊符号

```html
©	&copy;
®	&reg;
™	&trade;
<	&lt;
>	&gt;
&	&amp;
```

### 注释

```html
<!-- 注释内容 -->
```

### 列表

```HTML
<ul> <!-- unordered list -->
		<li>无序列表项</li> <!-- list item -->
		<li>无序列表项</li>
</ul>

<ul> <!-- ordered list -->
		<li>有序列表项</li> <!-- list item -->
		<li>有序列表项</li>
</ul>

<!-- https://knife.blog.csdn.net/article/details/121724575 -->
<dl> <!-- Definition List -->
    <dt></dt> <!--Definition Term -->
    <dd></dd> <!--Definition Description-->
    <dd></dd>
</dl>
```

## 多媒体标签

### 绝对路径

所有主机都能访问到的路径。

schema://hostname/path

http://www.test.com/home

### 相对路径

根相对路径

文档相对路径

### 图片

```html
<img src="path" alt="图片不能显示时的替代文本" width="像素|百分比" height="像素|百分比"><img/>
```

### 视频

```html
<video src="path" controls="controls" autoplay="autoplay" 
       width="像素|百分比" height="像素|百分比" 
       preload="auto|metadata|none" loop="loop">
	您的浏览器不支持video元素
</video>
```

### 音频

```HTML
<audio src="path" controls="controls" autoplay="autoplay" 
       preload="auto|metadata|none" loop="loop">

</audio>
```

### 多个多媒体标签

```html
<video controls="controls">
<source src="rabit.ogv" type="video/ogg"/>
<source src="rabit.mp4" type="video/mp4"/>
<source src="rabit.webm" type="video/webm"/>
您的浏览器不支持video元素
</video>

```

### embed

```html
<embed src=“url” width=“像素” height=“像素” type=“类型> </embed>
```

### 媒介分组

```html
<figure>
<figcaption>标题</figcaption>

</figure>

```

## 超链接

链接网页上的不同位置。

### a标签

```html
<a href="绝对路径">外部链接名</a>
<a href="相对路径">内部链接名</a>
<a href="path" type="mime_type" media="" hreflang="EN|CN"
   target="_self | _blank | _parent | _top" rel="not used"
   title="鼠标悬浮提示文本">
    链接名
</a>
```

### email

```html
<a href="mailto:html2013@126.com">请写电子邮件联系我们</a>
```

### 锚点链接（书签链接）

name属性用于定义锚记的名称，一个页面可以定义多个锚记

```html
<a href="#锚记名称">链接文本</a> 
<a name="锚记名称">…</a>

<a href="another_url#锚记名称">链接文本 </a> 
<a name="锚记名称">…</a>
```

### 图像映射

```html
<img src="path“  usemap="#图的名称"/>
<map name="图的名称"  id="图像映射名称">
    <area shape="形状" coords="区域坐标" href="URL" type="目标URL的MIME类型"/>
    <area shape="形状" coords="区域坐标" href="URL" type="目标URL的MIME类型"/>
    ......
</map>
                                                                 
<img src="images/breakfast.jpg" usemap="#mymap" />
<map name="mymap" id="mymap">
    <area href="path" shape="circle" coords="x,y,r" title="鼠标悬浮提示文本" />
    <area href="path" shape="rectangle" coords="x1,y1,x2,y2" title="鼠标悬浮提示文本" />  
    <area href="path" shape="polygon" coords="x1,y1,x2,y2,x3,y3,x4,y4" title="鼠标悬浮提示文本" />  
</map>

```

### iframe

```html
<iframe src="URL">……<iframe>

```

### base标签

```html
<base href="基准网址url" target="_self | _blank | _parent | _top"/>
<!--base>元素必须位于网页头部（head标签内）-->
<!--同一文档中，最多只能使用一个<base>元素-->
```

## 表格

不建议使用属性定义表格样式。

```html
<table border="1">
    <caption>表格标题</caption>
    <tr>
        <th>表头字段1</th>
        <th>表头字段2</th>
        <th>表头字段3</th>
    </tr>
    <tr>
        <th>数据</th>
        <td>数据</td>
        <td>数据</td>
    </tr>
</table>
```

### 列合并

```html
<table border="1">
    <caption>表格标题</caption>
    <tr>
        <td>A1</td>
        <td colspan="2">A2 A3</td>
        <!--<td>A3</td>-->
        <td>A4</td>
    </tr>
    <tr>
        <td>B1</td>
        <td>B2</td>
        <td>B3</td>
        <td>B4</td>
    </tr>
</table>
```

![image-20240302223922944](C:\Users\dell\AppData\Roaming\Typora\typora-user-images\image-20240302223922944.png)

### 行合并

```html
<table border="1">
    <caption>表格标题</caption>
    <tr>
        <td rowspan="2">A1<br/>B1</td>
        <td>A2</td>
        <td>A3</td>
        <td>A4</td>
    </tr>
    <tr>
        <!--<td>B1</td>-->
        <td>B2</td>
        <td>B3</td>
        <td>B4</td>
    </tr>
</table>
```

![image-20240302224247181](C:\Users\dell\AppData\Roaming\Typora\typora-user-images\image-20240302224247181.png)

### 行列合并

```html
<table border="1">
    <caption>表格标题</caption>
    <tr>
        <td>A1</td>
        <td>A2</td>
        <td>A3</td>
        <td>A4</td>
    </tr>
    <tr>
        <td>B1</td>
        <td>B2</td>
        <td rowspan="2" colspan="2">B3B4<br/>C3C4</td>
        <!--<td>B4</td>-->
    </tr>
    <tr>
        <td>C1</td>
        <td>C2</td>
        <!--<td>C3</td>-->
        <!--<td>C4</td>-->
    </tr>
</table>
```

![image-20240302225351617](C:\Users\dell\AppData\Roaming\Typora\typora-user-images\image-20240302225351617.png)

### 表格嵌套

```html
        <table border="1">
            <tr>
                <td>1</td>
                <td rowspan=2>2</td>
                <td>3</td>
                <td>4</td>
                <td>5</td>
            </tr>
            <tr>
                <td>6</td>
                <td>7</td>
                <td>8</td>
                <td>9</td>
            </tr>
            <tr>
                <td rowspan="2" colspan="2">10<br />
                    <table border=1>
                        <tr>
                            <td>1</td>
                            <td>2</td>
                            <td>3</td>
                        </tr>
                        <tr>
                            <td>4</td>
                            <td>5</td>
                            <td>6</td>
                        </tr>
                        <tr>
                            <td>7</td>
                            <td>8</td>
                            <td>9</td>
                        </tr>
                    </table>
                </td>
                <td>11</td>
                <td>12</td>
                <td>13</td>
            </tr>
            <tr>
                <td>14</td>
                <td colspan="2">15</td>
            </tr>
        </table>
```

![image-20240302225542226](C:\Users\dell\AppData\Roaming\Typora\typora-user-images\image-20240302225542226.png)

### 行分组

```html
<table>
    <thead>
    	<!-- 表头 -->
    </thead>
    <tbody>
    	<!-- 表格内容 -->
    </tbody>
    <tfoot>
    	<!-- 表格页脚、脚注、表注 -->
    </tfoot>
</table>
```

### 表格案例

课程表

简历

## 表单

```html
<form name="" method="get|post" action="url">
    <!--表单元素-->
</form>
```

### 表单域

```html
<input name="表单元素名称" size="" maxlength="" value="" checked
       type="text | password | radio | checkbox | submit | reset | button | image | file | hidden" />
```

#### 文本框

```html
<input type="text" name="名称" readonly="只读" size="宽度" maxlength="可输入字符数" value=”默认值”/>
```

#### 密码框

```html
<input type="password" name="名称" readonly="只读" size="宽度" maxlength="可输入字符数" value=”默认值”/>
```

#### 隐藏域

```html
<input type="hidden" name="hiddenText" value="1000"  />
```

#### 多行文本框

```html
<textarea rows="行数" cols="列数">
</textarea>
```

#### 复选框

必须保证同一组的复选框name属性一致

```html
<input type="checkbox" name="hobby" value="dancing" />跳舞<br />
<input type="checkbox" name="hobby" value="singing" />唱歌<br />
<input type="checkbox" name="hobby" value="basketball" />篮球<br />
<input type="checkbox" name="hobby" value="pingpang" />乒乓球<br />
```

#### 单选框

必须保证同一组的单选框name属性一致

```html
<input type="radio" name="gender" value="1" checked="checked"/>男生<br />
<input type="radio" name="gender" value="0" />女生
```

#### 文件上传

```html
<input type="file" name="user_file" />
```

#### 下拉选择框

```html
<select>
   	<option value="1">C++</option>
   	<option value="2">Java</option>
   	<option value="3">Html</option>
</select>
```

#### datalist

```html
<input type="url" list="url_list" name="link" />
	<datalist id="url_list">
		<option label="W3School" value="http://www.W3School.com.cn" />
		<option label="Google" value="http://www.google.com" />
		<option label="Microsoft" value="http://www.microsoft.com" />
	</datalist>
```

### 表单按钮

提交按钮

```html
<input type="submit" value="提交按钮" />
```

复位按钮

```html
<input type="reset" value="重置按钮" />
```

普通按钮

```html
<input type="button" value="普通按钮" />
```

图片按钮

```html
<input type="image" src="images/submit.jpg" width="120"/>
```

### 高级表单

URL表单

```html
<input type="url" name="名称"/>
```

Email表单

```html
<input type="email" name="名称" />
```

日期和时间表单

```html
<input type="时间日期关键字" name="名称" />
<input name="txtDate_1" type="date"/><br/>
<input name="txtDate_2" type="time"><br/>
  	月份与星期类型输入框：<br/>
<input name="txtDate_3" type="month"/><br/>
<input name=“txtDate_4” type=“week”/><br/>
	日期时间型输入框：<br/>
<input name="txtDate_5" type="datetime"/><br/>
<input name="txtDate_6" type="datetime-local"/><br/>
```

![image-20240303193017687](C:\Users\dell\AppData\Roaming\Typora\typora-user-images\image-20240303193017687.png)

数字表单

```html
<input type="range | number" name="名称" min="最小值" max="最大值" step="步长" value="初始值" />
<form>
	输入0—100之间的数字：
	<input type="range" name="inputNum3" min="1" max="100" value="30"/><br/>
	输入10-50之间的数字(步长为2)：
	<input type="number" name="inputNum2" min="10" max="50" step="2" />
</form>

```

color表单

```html
<input type="color" name="名称" />
```

表单分组

```html
<form>
  <fieldset>
    <legend>控件组的标题</legend>
   		……
  </fieldset>
</form>	
<form>
  	<fieldset>
    	<legend>用户登录</legend><br/>
			用户名：<input type="text" name="uname" /><br /><br />
			密&nbsp;码：<input type="password" name="upass" /><br /><br />
			<input type="submit" value="提交"/>
  	</fieldset>
	</form>

```

搜索表单

```html
<input type="search" name="usearch" />
```

电话表单

```html
<input type="tel" name="phone" />
```

### 表单通用属性

```html
<input autofocus="autofocus" multiple="multiple" required="required" placeholder="默认内容" pattern="正则表达式"/>
```

表单案例：申请注册

![image-20240303194449826](C:\Users\dell\AppData\Roaming\Typora\typora-user-images\image-20240303194449826.png)

## 特殊字符

```html
&nbsp; 不换行空格，全称No-Break Space
&ensp; 半角空格，全称是En Space
&emsp; 全角空格，全称是Em Space
&thinsp; 窄空格，全称是Thin Space
&zwnj; 零宽不连字，全称是Zero Width Non Joiner，简称“ZWNJ”，是一个不打印字符
&zwj; 零宽连字，全称是Zero Width Joiner，简称“ZWJ”，是一个不打印字符
```

