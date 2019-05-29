**Identity Server 4 原理和实战**

B站地址 https://www.bilibili.com/video/av42364337

1.  OAuth 2.0简介(上)<br/>
    开放授权(OAuth)是一个开放标准，允许用户让第三方应用访问该用户在某一网站上存储的私密的资源（如照片，视频，联系人列表），而无需将用户名和密码提供给第三方应用。<br/>
    OAuth允许用户提供一个令牌，而不是用户名和密码来访问他们存放在特定服务提供者的数据。每一个令牌授权一个特定的网站（例如，视频编辑网站）在特定的时段（例如，接下来的2小时内）内访问特定的资源（例如仅仅是某一相册中的视频）。<br/>
    这样，OAuth让用户可以授权第三方网站访问他们存储在另外服务提供者的某些特定信息，而非所有内容。<br/>
    OAuth 2.0是OAuth协议的下一版本，但不向下兼容OAuth 1.0。OAuth 2.0关注客户端开发者的简易性，同时为Web应用、桌面应用、手机和职能设备提供专门的认证流程。<br/>
    应用从资源的所有者那里得到授权(Authorization)和访问令牌(access token)，随后就可以使用这个access token来访问资源。<br/>

    Identity Server 4 基于OAuth 2.0 和OpenId Connect ，实现了主要功能。<br/>
    不是身份认证协议<br/>

2.  OAuth 2.0简介(下)<br/>
    1. 端点(Endpoint) 
       1. 授权端点 Authorization Endpoint
       2. Token端点 Token Endpoint
    2. 范围(Scope) 代表资源所有者在被保护资源那里的一些权限
    3. 访问令牌(Access Token) 访问被保护资源的凭据
    4. Refresh Token 用来获取Access Token
    5. 发生错误时
    6. 错误的类型
   
3. OpenID Connet简介<br/>
   身份认证 Authentication<br/>
   授权     Authorization<br/>
   1. OAuth 2.0与身份认证协议的角色映射
   2. 为什么不使用OAuth 2.0里的access token来解决这个问题呢？
   3. OpenID Connect协议
   4. OpenID Connect三个流程(Flow)
   
   
