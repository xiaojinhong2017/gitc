from django.utils.deprecation import MiddlewareMixin
class Row(MiddlewareMixin):
    def process_request(self,request):
        print '----------------'
    def process_response(self,request,response):
        print '+++++++++++++++++'
        return response
