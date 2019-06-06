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
            1.  可以在制作镜像时，直接吧源码嵌入里面（不考虑这个）
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