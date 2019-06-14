**Docker 和 ASP.NET Core Web应用**

B站地址 https://www.bilibili.com/video/av35227304

**linux容器还是windows容器，需要特别注意下。在windows容器下好多都不能pull上。**

1.  Docker 安装 和 容器原理及简介
    1.  现在hello-world不支持windows了，现在测试用我用的是hello-seattle
2.  镜像
    1.  用了下 docker rmi 命令
3.  容器的常规操作
    1.  docker run <镜像>
        1.  docker run -d <镜像>    分离模式
        2.  docker run -it <镜像>   交互模式
    2.  docker pull <镜像>
    3.  docker images
    4.  docker rmi
    5.  docker ps, docker ps -a 列出所有的容器
    6.  docker stop <容器> 停止容器
    7.  docker rm <容器> 删除所有停止的容器
    8.  docker start <容器> 重启停止的容器
    9.  ctrl+c  =>  ctrl+p, ctrl+q 退出
    10. docker exec -it 镜像id /bin/bash        进入linux镜像
4.  Swarms 集群模式
    1.  Cluster就是Swarm
    2.  Swarm里面的Docker引擎就是运行于swarm模式下
5.  建立swarm（有点复杂啊，而且是在linux虚拟机下操作的，自己没有做）
6.  Services
7.  Services  扩展和升级
    1.  扩展
    2.  批量更新service
8.  Swarm Stack</br>
    stack 是构成热定环境中的service集合，他是自动部署多个相互关联的服务的简便方法，而无需单独定义每个服务。</br>
    stack file 是一种yaml格式的文件，类似于docker-compose.yml文件，它定义了一个或多个服务，</br>
    并定义了服务的环境变量、部署标签、容器数量及相关的环境特定配置等。</br>
    1.  visualizer查看stack分布情况

**docker下半部分，生产环境中实际应用**

9.  Volume把源码挂到容器中
    1.  分层文件系统
        1.  docker的文件和镜像也是类似分层文件系统，镜像是共享的，镜像上加一层，成为容器
        2.  镜像层都是只读的
        3.  容器层是可读写的
        4.  容器被删除了的话，写入的数据，也没有了，那么，需要使用volume
    2.  Volume卷
        1.  如何把源代码装进容器里
            1.  可以在制作镜像时，直接把源码嵌入里面（不考虑这个）
            2.  把源码挂载到容器的可读写层
        2.  Volume（卷）是容器中的一个特别种类的目录，通常叫做数据卷，里面放置各种类型的数据，<br/>
            例如：代码、日志文件、数据文件等等。
        3.  Volume可以在容器见共享和复用。可以让多个容器对同一个volume进行读写，也可以让一个容器读写多个volume
        4.  对镜像的更形比不过不会影响volume
        5.  volume是被持久化的，即使容器被删除了，它仍然还存在
        6.  数据会存在Docker Host中
        7.  本地源码放入docker中（待测）

10. 定制镜像
    1.  Dockerfile
    2.  docker build

11. 发布镜像
    1.  docker login
    2.  docker push

12. 容器网络
    1.  连接方式

13. Docker Compose
    1.  Compose是一个用来定义和运行多容器Docker应用的工具。<br/>
        使用Compose的时候，你可以使用一个YAML文件来配置你应用的服务。<br/>
        然后根据配置，使用一个命令即可创建并运行所有的服务。<br/>
    2.  Docker Compose可以做很多事情，但是如果只考虑在开发环境里，他可以做下面这些事情<br/>
        1.  管理整个应用的生命周期：启动、停止、重构建服务，而服务呢，其实就是运行的容器而已；<br/>
        2.  查看在运行的服务的状态，包括输出日志；<br/>
        3.  可以在单个容器上运行一次性命令。<br/>
    3.  通常来水，如果你的应用稍微有点规模，例如你的Web应用需要使用Web服务器、缓存服务器、数据库服务器等，<br/>
        如果有你手动管理这样的docker应用，就很繁琐，也很容易出错。<br/>
        而使用Docker Compose的话，他可以定义一个docker-compose.yml文件，这个文件里，你可以定义所有的这些服务及他们的关系。<br/>

**Dockerfile reference**

https://docs.docker.com/engine/reference/builder/

Docker can build images automatically by reading the instructions from a **Dockerfile**. A **Dockerfile** is a text document that contains<br/>
all the commands a user could call on the command line to assemble an image. Using **docker build** users can create an automated<br/>
build that executes several command-line instructions in succession.<br/>

>Docker会通过dockerfile的指令来自动创建镜像。一个dockerfile是一个文本文件，包含了用户可以调用命令行上的所有用来组装镜像的命令。<br/>
>使用docker build命令，用户可以可以创建一个自动化的连续执行多个命令行指令。<br/>


1. Usage
   1. docker build -f  f指向dockerfile文件
   2. -t 使用镜像, 给生成的镜像命名
2. FROM 来源的
3. WORKDIR 路径
4. EXPOSE 端口
5. COPY 复制
6. RUN 编译
7. ENTRYPOINT 入口点，配置容器启动时运行的命令，可以让容器以应用程序或服务的形式运行。
   1. Exec格式：ENTRYPOINT ["executable","param1","param2"]这是ENTRYPOINT的推荐格式
   2. Shell格式：ENTRYPOINT command param1 param2
   3. 