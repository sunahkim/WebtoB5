*DOMAIN
webtob1

*NODE
webtob   WEBTOBDIR="ENV["APP_ROOT"]/webtob",
                SHMKEY = 54030,
                DOCROOT="ENV["APP_ROOT"]/webtob/docs",
                PORT = "ENV[¡®PORT¡¯]",
                #PORT = "5580",
                HTH = 1,
                #Group = "nobody",
                #User = "nobody",
                NODENAME = "$(NODENAME)",
                ERRORDOCUMENT = "503",
                #Options="IgnoreExpect100Continue",
                LOGGING = "log1",
                ERRORLOG = "log2",
                SYSLOG = "syslog"#,
                #MimetypesConfig=""

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
#html            SVGNAME = htmlg, MinProc = 2, MaxProc = 10, ASQCount = 1
cgi             SVGNAME = cgig, MinProc = 2, MaxProc = 10, ASQCount = 1
ssi             SVGNAME = ssig, MinProc = 2, MaxProc = 10, ASQCount = 1

*URI

*ALIAS
alias1          URI = "/cgi-bin/", RealPath = "ENV["APP_ROOT"]/webtob/cgi-bin/"

*LOGGING
syslog          Format = "SYSLOG", FileName = "ENV["APP_ROOT"]/webtob/log/system.log_%M%%D%%Y%",
                        Option = "sync"
log1            Format = "DEFAULT", FileName = "ENV["APP_ROOT"]/webtob/log/access.log_%M%%D%%Y%",
                        Option = "sync"
log2            Format = "ERROR", FileName = "ENV["APP_ROOT"]/webtob/log/error.log_%M%%D%%Y%",
                        Option = "sync"

*ERRORDOCUMENT
503                     status = 503,
                        url = "/503.html"

*EXT
txt             MimeType = "text/html", SvrType = HTML
htm             MimeType = "text/html", SvrType = HTML
