#coding=utf-8
from django.conf.urls import url
# from bookapp import views
from bookapp.views import *
from django.views.generic.base import TemplateView
from django.views.generic.base import RedirectView
urlpatterns = [
     url(r'^hello/$',hello),
     url(r'^time/$',get_time),
     url(r'^jump/$',jump),
     url(r'^error/$',error),
     url(r'^argument/$',argument,{'a':1,'b':2}),
    #  url(r'^(argument1/(1)/(2))$',argument1})
     url(r'^argument1/(?P<offset>\d{1,2})$',argument1)

]

urlpatterns += [
url(r'^template/$',template),
url(r'^tag/$',tag),
url(r'^filter/$',filter),
url(r'^extend/$',extend,name = 'extend'),
url(r'^include/$',include),
url(r'^static/$',static),
url(r'^global/$',global_template),
]

#通用视图

urlpatterns += [
url(r'^about/$',TemplateView.as_view(template_name = 'ind.html')),
url(r'^redirect/$',RedirectView.as_view(url = 'http://www.baidu.com'))
]

# 与数据相关
urlpatterns += [
url(r'^add/(?P<table>author)/$',add_data),
url(r'^add/(?P<table>book)/$',add_data),
url(r'^add/(?P<table>publisher)/$',add_data),
url(r'^delete/(?P<table>book)/$',del_data),
url(r'^update/$',update_data),
url(r'^select/$',select_data),
url(r'^foreign/$',foreign),
url(r'^sql/$',sql),
]
urlpatterns += [

url(r'^article/$',article),
url(r'^upload/(?P<dir_name>)[^/]+$',image),
]
