#include <stdio.h>
#include <stdlib.h>

// تخصيص الذاكرة للسلسلة
char *ChargerChaine(int N) {
    char *chaine = (char*)malloc(N + 1);   
    if (chaine == NULL) {
        printf("Memory allocation error\n");  // إذا فشل تخصيص الذاكرة
    exit(1);
    }
    printf("Enter the series: ");
    scanf("%s", chaine);   // قراءة السلسلة النصية

    return chaine;
}

int Longueur(char *ch) {
    int i = 0;
    while (ch[i] != '\0') { // نمر عبر السلسلة حتى نصل إلى نهاية السلسلة
        i++;   // زيادة العداد
    }
    return i;   // إرجاع الطول
}

// تحميل السلسلة من المستخدم
void ChargerTab(char *p, char Tab[]) {
    int i = 0;
    while (p[i] != '\0') {  // ننسخ السلسلة حرفًا بحرف
        Tab[i] = p[i];
        i++;
    }
    Tab[i] = '\0';  // إضافة المحرف '\0' في نهاية السلسلة
}

void InverserTab(char Tab[], int n) {
    char temp;
    for (int i = 0; i < n / 2; i++) {
        temp = Tab[i];   // حفظ العنصر الحالي في مكان مؤقت
        Tab[i] = Tab[n - i - 1];   // تبديل العنصر الأول بالعنصر الأخير
        Tab[n - i - 1] = temp;  // وضع العنصر المؤقت في المكان الأخير 
    }
}

void AfficherTab(char Tab[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%c", Tab[i]);   // طباعة كل حرف في السلسلة
    }
    printf("\n");  // إضافة سطر جديد بعد الطباعة
}

int main() {
    int N;
    printf("Enter the maximum length of the string: ");
    scanf("%d", &N);    // إدخال طول السلسلة

    if (N <= 0) {
        printf("Please enter a positive number for N.\n");  // إذا كان الطول غير صحيح
        return 1;  // إذا كانت الذاكرة غير مخصصة بنجاح، التوقف عن التنفيذ
    }

    
    char *chaine = ChargerChaine(N);   // قراءة السلسلة

    // حساب طول السلسلة
    int longueur = Longueur(chaine);

    // تخصيص مصفوفة لتخزين السلسلة
    char Tab[longueur + 1];  
    ChargerTab(chaine, Tab);  // نقل السلسلة إلى المصفوفة

    // طباعة السلسلة الأصلية
    printf("Original series: ");
    AfficherTab(Tab, longueur);

    // عكس السلسلة
    InverserTab(Tab, longueur);
    printf("Inverse series: ");
    AfficherTab(Tab, longueur);
    // تحرير الذاكرة المخصصة
    free(chaine);

    return 0;
}

