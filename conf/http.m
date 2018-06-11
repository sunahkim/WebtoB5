*DOMAIN
webtob1

*NODE
qpsx1   WEBTOBDIR="$WEBTOBDIR",
                SHMKEY = 54030,
                DOCROOT="$WEBTOBDIR/docs",
                PORT = "5580",
                HTH = 1,
                #Group = "nobody",
                #User = "nobody",
                NODENAME = "$(NODENAME)",
                ERRORDOCUMENT = "503",
                #Options="IgnoreExpect100Continue",
                LOGGING = "log1",
                ERRORLOG = "log2",
                SYSLOG = "syslog"
        #       JSVPORT = 34423

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
#jsvg           NODENAME = "qpsx1", SVRTYPE = JSV

*SERVER
html            SVGNAME = htmlg, MinProc = 2, MaxProc = 10, ASQCount = 1
cgi             SVGNAME = cgig, MinProc = 2, MaxProc = 10, ASQCount = 1
ssi             SVGNAME = ssig, MinProc = 2, MaxProc = 10, ASQCount = 1
#MyGroup                SVGNAME = jsvg, MinProc = 10, MaxProc = 10

*URI
#uri1           Uri = "/",   Svrtype = HTML
#uri2            Uri = "/examples/",  SvrType=JSV, SvrName=MyGroup

*ALIAS
alias1          URI = "/cgi-bin/", RealPath = "$WEBTOBDIR/cgi-bin/"

*LOGGING
syslog          Format = "SYSLOG", FileName = "$WEBTOBDIR/log/system.log_%M%%D%%Y%",
                        Option = "sync"
log1            Format = "DEFAULT", FileName = "$WEBTOBDIR/log/access.log_%M%%D%%Y%",
                        Option = "sync"
log2            Format = "ERROR", FileName = "$WEBTOBDIR/log/error.log_%M%%D%%Y%",
                        Option = "sync"

*ERRORDOCUMENT
503                     status = 503,
                        url = "/503.html"

*EXT
txt             MimeType = "text/html", SvrType = HTML
htm             MimeType = "text/html", SvrType = HTML
#jsp            Mimetype ="application/jsp",  Svrtype=JSV,  SvrName=MyGroup
