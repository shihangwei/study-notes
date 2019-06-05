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