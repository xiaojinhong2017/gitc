from django.conf.urls import url
from blogapp.views import *
urlpatterns = [
url(r'^$',origin),
url(r'^content/(?P<arg>\d{1,2})',content),
# url(r'^/content/(arg)$',content),
url(r'^write/$',login_write),
url(r'^login/$',login),
url(r'^logout/$',logout),
url(r'^submit/$',submit),

]
