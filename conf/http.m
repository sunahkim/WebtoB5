*DOMAIN
webtob1

*NODE
webtob   WEBTOBDIR="$WEBTOBDIR",
                SHMKEY = 54030,
                DOCROOT="$WEBTOBDIR/docs",
                PORT = "8080",
                HTH = 1,
                #Group = "nobody",
                #User = "nobody",
                NODENAME = "$(NODENAME)",
                ERRORDOCUMENT = "503",
                #Options="IgnoreExpect100Continue",
                LOGGING = "log1",
                ERRORLOG = "log2",
                SYSLOG = "syslog"

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
alias1          URI = "/cgi-bin/", RealPath = "$WEBTOBDIR/cgi-bin/"

*LOGGING
syslog          Format = "SYSLOG", FileName = "log/system.log_%M%%D%%Y%",
                        Option = "sync"
log1            Format = "DEFAULT", FileName = "log/access.log_%M%%D%%Y%",
                        Option = "sync"
log2            Format = "ERROR", FileName = "log/error.log_%M%%D%%Y%",
                        Option = "sync"

*ERRORDOCUMENT
503                     status = 503,
                        url = "/503.html"

*EXT
txt             MimeType = "text/html", SvrType = HTML
htm             MimeType = "text/html", SvrType = HTML
