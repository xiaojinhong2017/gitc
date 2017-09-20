#coding=utf-8
from django.conf import settings
def global_setting(request):
    site = '人生如戏，全靠演技'
    tel = '18810207835'
    email = 'lvze_work@126.com'
    basedir = settings.BASE_DIR

    return locals()
