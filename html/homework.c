#include <stdio.h>

int main(void)
{
    printf("content type : text/html\n\n");
    printf("<html lang=en>\n");
    printf("<head><meta charset=\"UTF-8\"><title>An html page from a cgi</title>\n");
    printf("<style type=\"text/css\">\n");
    printf("h2{color: blue; text-align: left;background-color: #CCCCCC}");
    printf("</style></head>\n");
    printf("<body>\n");
    printf("<h2>个人疾病史</h2>\n");
    printf("<p style=font-size:14px;color:red;>问卷填写说明：所有标注！图标为必填项！</p>\n");
    printf("<p>01.您是否患有下列疾病，若有请选择，否则不用填写.</p>\n");
    printf("<table>\n");
    printf("<tr>\n");
    printf("<td><input type = \"checkbox\" name =\"illness\" value = \"0\"/>1型糖尿病</td>\n");
    printf("<td><input type = \"checkbox\" name =\"illness\" value = \"0\"/>2型糖尿病</td>\n");
    printf("<td><input type = \"checkbox\" name =\"illness\" value = \"0\"/>高血压</td>\n");
    printf("<td><input type = \"checkbox\" name =\"illness\" value = \"0\"/>血脂异常</td>\n");
    printf("</tr>\n");
    printf("<tr>\n");
    printf("<td><input type = \"checkbox\" name =\"illness\" value = \"0\"/>痛风/高尿酸血症</td>\n");
    printf("<td><input type = \"checkbox\" name =\"illness\" value = \"0\"/>冠心病/脑卒中</td>\n");
    printf("<td><input type = \"checkbox\" name =\"illness\" value = \"0\"/>慢性支气管炎</td>\n");
    printf("<td><input type = \"checkbox\" name =\"illness\" value = \"0\"/>肺气肿</td>\n");
    printf("</tr>\n");
    printf("<tr>\n");
    printf("<td><input type = \"checkbox\" name =\"illness\" value = \"0\"/>肺癌</td>\n");
    printf("<td><input type = \"checkbox\" name =\"illness\" value = \"0\"/>前列腺疾病史</td>\n");
    printf("<td><input type = \"checkbox\" name =\"illness\" value = \"0\"/>前列腺癌</td>\n");
    printf("<td><input type = \"checkbox\" name =\"illness\" value = \"0\"/>骨质疏松症</td>\n");
    printf("</tr>\n");
    printf("<tr>\n");
    printf("<td><input type = \"checkbox\" name =\"illness\" value = \"0\"/>既往骨折史</td>\n");
    printf("<td><input type = \"checkbox\" name =\"illness\" value = \"0\"/>类风湿性关节炎</td>\n");
    printf("</tr>\n");
    printf("</table>\n");
    printf("<p>02.您是否患有与骨质疏松紧密相关的疾病，包括成年骨不全症，为治疗的长期甲状腺机能抗进，性腺机能减退，慢性营养不良以及慢性肝病等?</p>\n");
    printf("<form>\n");
    printf("<input type=\"radio\" name =\"choose\" value=\"yes\"/>是\n");
    printf("<input type=\"radio\" name =\"choose\" value=\"no\"/>否\n");
    printf("</form>\n");
    printf("<p>03.您是否目前正在服用或曾经服用过肾上腺皮质激素（如强的松，地塞米松等）超过三个月？</p>\n");
    printf("<form>\n");
    printf("<input type=\"radio\" name =\"choose\" value=\"yes\"/>是\n");
    printf("<input type=\"radio\" name =\"choose\" value=\"no\"/>否\n");
    printf("<p align=\"right\"><input type=\"submit\" style=\"color: white;background-color:blue;\" value=\"上一页\"><input type=\"submit\" style=\"color:white; background-color:green;\" value=\"暂存问卷\"><input type=\"submit\" style=\"color:white;background-color:blue;\" value=\"下一页\">\n");
    printf("</form>\n");
    printf("</body>\n");
    printf("</html>\n");
    fflush(stdout);
    return 0;
}
