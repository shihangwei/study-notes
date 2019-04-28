**在阿里云ecs上安装的mysql(8.0.12)及远程连接问题**


1. ecs上 **telnet 0.0.0.0 3306** 端口访问不了的问题<br/>
   1.1. 服务器上确认3306的入口是OK<br/>
   1.2. 确认阿里云的安全规则中，入口方向是不是开了3306的端口<br/>
   以上动作保证，远程可以telnet到服务器<br/>

2. mysql远程连接 **登录** <br/>
   2.1. 首先确认是不是所有的外部ip都可以连接，user表中的localhost -> % <br/>
   2.2. 8.0.12和之前的连接方式不一样，需要修改，user表中的 cache... -> mysql_native_password <br/>
   2.3. 错误：access denied for user'root'@''(using passworkd:YES) ，需要重置下用户的密码 ALTER USER 'root'@'localhost' IDENTIFIED WITH mysql_native_password BY '你的新密码'<br/>
   以上动作保证，远程连接到mysql<br/>