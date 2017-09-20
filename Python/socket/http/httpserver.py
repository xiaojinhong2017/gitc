from BaseHTTPServer import BaseHTTPRequestHandler,HTTPServer

class RequestHandler(BaseHTTPRequestHandler):
    def do_GET(self):
        print 'do method get'
        # print self.rfile.read()
        self.wfile.write('helloworld')
        return
    def do_POST(self):
        return

address = ('127.0.0.1',8000)
server = HTTPServer(address,RequestHandler)
server.serve_forever()
