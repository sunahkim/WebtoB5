# DEPRECIATED
This buildpack has been depreciated in favour of the more up to date (and better named) https://github.com/cloudfoundry-community/staticfile-buildpack.  Please use that instead.

---

# A buildpack for hosting static HTML websites on Cloud Foundry using WebtoB

## Using this buildpack as-is

Ensure that your app's root folder has an `index.html` or `index.htm` or `Default.htm` file (which will be served as the default page).

Run:

```
cf push -b https://github.com/sunahkim/WebtoB5.git
```

## Custom configuration files

You can customise the configuration by adding a `http.m` to your root folder.

If the buildpack detects this file it will be used in place of the built-in `http.m`, and run through the
same erb processor.  An example of the most basic `http.m` (this is the one included in the build pack's `http.m` directory):

```
*DOMAIN
webtob1

*NODE
qpsx1   WEBTOBDIR="$APP_ROOT/webtob",
                SHMKEY = 54030,
                DOCROOT="$APP_ROOT/webtob/docs",
                PORT = "5580",
                HTH = 1,
                #Group = "nobody",
                #User = "nobody",
                NODENAME = "$(NODENAME)",
                ERRORDOCUMENT = "503",
                #Options="IgnoreExpect100Continue",
                LOGGING = "log1",
                ERRORLOG = "log2",
                SYSLOG = "syslog",
                MimetypesConfig=""

*HTH_THREAD
hth_worker
                  SendfileThreads = 4,
                  #AccessLogThread = Y,
                  #ReadBufSize=1048576, #1M
                  HtmlsCompression="text/html",
                  SendfileThreshold=1,
                  WorkerThreads=8


*SVRGROUP
htmlg           NODENAME = "qpsx1", SVRTYPE = HTML
cgig            NODENAME = "qpsx1", SVRTYPE = CGI
ssig            NODENAME = "qpsx1", SVRTYPE = SSI

*SERVER
html            SVGNAME = htmlg, MinProc = 2, MaxProc = 10, ASQCount = 1
cgi             SVGNAME = cgig, MinProc = 2, MaxProc = 10, ASQCount = 1
ssi             SVGNAME = ssig, MinProc = 2, MaxProc = 10, ASQCount = 1

*URI

*ALIAS
alias1          URI = "/cgi-bin/", RealPath = "$APP_ROOT/webtob/cgi-bin/"

*LOGGING
syslog          Format = "SYSLOG", FileName = "$APP_ROOT/webtob/log/system.log_%M%%D%%Y%",
                        Option = "sync"
log1            Format = "DEFAULT", FileName = "$APP_ROOT/webtob/log/access.log_%M%%D%%Y%",
                        Option = "sync"
log2            Format = "ERROR", FileName = "$APP_ROOT/webtob/log/error.log_%M%%D%%Y%",
                        Option = "sync"

*ERRORDOCUMENT
503                     status = 503,
                        url = "/503.html"

*EXT
txt             MimeType = "text/html", SvrType = HTML
htm             MimeType = "text/html", SvrType = HTML
```
