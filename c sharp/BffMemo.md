**搭建OrgBff笔记**

1. Swagger<br/>
   使用的是Swashbuckle.AspNetCore 包<br/>
    1. 配置都在CustomSwaggerExtension中完成，在startup.cs中的ConfigureServices()方法中添加CustomSwaggerExtension的swagger配置。
    2. 需要comments在生成xml的时候，不生成对应的xml文件，需要修改项目.csproj文件，添加代码：
        ```
        <PropertyGroup>
            <GenerateDocumentationFile>true</GenerateDocumentationFile>
            <NoWarm>$(NoWarn):1591</NoWarm>
        </PropertyGroup>
        ```
    3. 默认首页到swagger，设置LaunchSettings.json文件，添加：
        ```
        "launchUrl":"swagger"
        ```
    4. swagger的4种filter：documentFilter、operationFilter、parameterFilter、schemaFilter
    5. token的添加
        1. options.AddSecurityDefinition("Bearer",new ApiKeyScheme())...
        2. options.AddSecurityRequirement()...
    6. 在api route中有V1这样的版本，那么，需要在swagger中去掉这样的版本号
       1. options.OperationFilter中去掉**v1**这样的参数描述
       2. options.DocumentFilter中替换掉**v{version}**这样的版本信息，用**options.SwaggerDoc**中的info.Version内容
    7. 在route中带有ApiVersion的话，需要在startup中的ConfigureServices中，添加**services.AddApiVersioning**设置
    8. 按照微软的sample配置 https://docs.microsoft.com/zh-cn/aspnet/core/tutorials/getting-started-with-swashbuckle?view=aspnetcore-2.2&tabs=visual-studio

2. Startup.cs中的各种配置
    1. Swagger的配置<br/>
        添加CustomSwaggerExtension，swagger的各种设定在CustomSwaggerExtension内部完成。
    2. ApiVersion<br/>
        services.AddApiVersioning来添加版本设置

3. Serilog<br/>
4. 跨域Cors解决
   1. 按照微软的sample配置 https://docs.microsoft.com/zh-cn/aspnet/core/security/cors?view=aspnetcore-2.2 
   2. CustomCorsService
      1. override CorsService =》 扩展内容作用 TODO
      2. string的 MatchWildcardOrigin 的扩展
      3. services.Configure<MvcOptions> 的设置