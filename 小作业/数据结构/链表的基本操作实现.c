#include <stdio.h>
  2 #include <malloc.h>
  3 #define LEN sizeof(struct student)
  4
  5 /*----------------���ݶ���----------------------*/
  6
  7 //����һ��ѧ����Ϣ�Ľṹ��,����ѧ��,�����ͽṹ�����͵�ָ��
  8 struct student
  9 {
 10     long num;                //ѧ��
 11     char name[128];            //����
 12     struct student *next;    //�ṹ��ָ��
 13 };
 14
 15 typedef struct student * stuNode;
 16
 17 int n=0;                    //ȫ�ֱ���,��¼����ĳ���
 18
 19 /*---------------��������---------------------*/
 20
 21 stuNode Create();            //����һ���µ�����
 22
 23 void Print(stuNode head);    //ͨ�����������ͷָ���ӡ��������
 24
 25 stuNode Delete(stuNode head,int num);    //ͨ�����������ͷָ���ѧ��ѧ��ɾ���ڵ�
 26
 27 stuNode Insert(stuNode head,stuNode newStu);    //����ѧ��ѧ�ŵ�˳���������в�����Ԫ��
 28
 29
 30 /*---------------��������----------------------*/
 31
 32 struct student *Create()
 33 {
 34     struct student *head,*p1,*p2;
 35
 36     //����һ��LEN��С�Ŀռ�,����p1,p2ָ��ָ����
 37     p2=p1=(struct student *)malloc(LEN);
 38     //��ͷָ����ΪNULL
 39     head=NULL;
 40
 41     //��������ڵ㲢���ڵ��Ԫ�ظ�ֵ
 42     printf("������ѧ����ѧ�ź�����:");
 43     scanf("%ld %s",&p1->num,p1->name);
 44     while(p1->num!=0)
 45     {
 46         n=n+1;
 47         if(NULL==head)
 48         {
 49             head=p1;
 50         }
 51         else
 52         {
 53             p2->next=p1;
 54         }
 55         p2=p1;
 56         p1=(struct student *)malloc(LEN);
 57         printf("������ѧ����ѧ�ź�����:");
 58         scanf("%ld %s",&p1->num,p1->name);
 59     }
 60     //��β�ڵ��ָ����ΪNULL
 61     p2->next=NULL;
 62     return head;
 63 }
 64
 65
 66 void Print(struct student *head)
 67 {
 68     struct student * p;
 69     p=head;
 70
 71     //�ж������Ƿ�Ϊ��
 72     if(NULL==head)
 73     {
 74         printf("����Ϊ��!\n");
 75         return head;
 76     }
 77     else
 78     {
 79         //ѭ����ӡ�����е�Ԫ��
 80         printf("%d ����¼�ֱ�Ϊ:\n",n);
 81         while(p!=NULL)
 82         {
 83             printf("%ld %s\n",p->num,p->name);
 84             //ָ��ָ����һ���ڵ�
 85             p=p->next;
 86         }
 87     }
 88 }
 89
 90
 91 struct student *Delete(struct student * head,int num)
 92 {
 93     struct student *p1;
 94     struct student *p2;
 95     p1=head;
 96     //�ж������Ƿ�Ϊ��
 97     if(NULL==head)
 98     {
 99         printf("����Ϊ��!\n");
100         return head;
101     }
102     //�����ڵ�,�жϵ�ǰ�ڵ��ǲ�����Ҫɾ���Ľڵ㼰�Ƿ�Ϊβ�ڵ�
103     //����ҵ���Ӧ�ڵ�,�����Ѿ�������β�ڵ������ѭ��
104     while(p1->num!=num&&p1->next!=NULL)
105     {
106         p2=p1;
107         p1=p1->next;
108     }
109     //�ж��Ƿ��ҵ���Ӧ�ڵ�
110     if(p1->num==num)
111     {
112         //Ҫɾ���Ľڵ��ǲ�������ĵ�һ���ڵ�
113         //�����,�ͽ�ͷָ��ָ��ýڵ�ĺ�һ���ڵ�
114         //�������,�ͽ��ýڵ��ǰһ���ڵ��ָ��ָ��ýڵ�ĺ�һ���ڵ�
115         if(head==p1)
116         {
117             head=p1->next;
118         }
119         else
120         {
121             p2->next=p1->next;
122         }
123         n=n-1;
124         printf("%ld �ڵ���ɾ��.\n",num);
125     }
126     else
127     {
128         printf("������û��Ҫɾ����Ԫ��.\n");
129     }
130     return head;
131 }
132
133
134 struct student *Insert(struct student * head,struct student * newStu)
135 {
136     struct student *p0;
137     struct student *p1;
138     struct student *p2;
139     p0=newStu;
140     p1=head;
141     //�ж������Ƿ�Ϊ��,����ǿ�����,�ͽ��½ڵ���Ϊ��һ���ڵ�
142     if(NULL==head)
143     {
144         head=p0;
145         p0->next=NULL;
146     }
147     else
148     {
149         //����ÿһ���ڵ��е�ѧ��,����ѧ�űȽϴ�С
150         //����ҵ�һ��ѧ�ű���ѧ�Ŵ�,�ͽ���ѧ�ŵĽڵ������֮ǰ
151         //���β�ڵ��ѧ���Ա���ѧ��С,�ͽ��½ڵ���뵽����β��
152         while((p0->num > p1->num)&&(p1->next!=NULL))
153         {
154             p2=p1;
155             p1=p1->next;
156         }
157         //�ҵ�һ������ѧ�Ŵ�Ľڵ�
158         if(p0->num <= p1->num)
159         {
160             //�жϸýڵ��Ƿ�Ϊͷ�ڵ�,�����,���½ڵ�����Ϊͷ�ڵ�
161             if(p1==head)
162             {
163                 head=p0;
164             }
165             else
166             {
167                 p2->next=p0;
168             }
169               p0->next=p1;
170         }
171         else
172         {
173             p1->next=p0;
174             p0->next=NULL;
175         }
176     }
177     //�����ȼ�1
178     n=n+1;
179     printf("%ld ����ɹ�!\n",newStu->num);
180     return head;
181 }
182
183 void main()
184 {
185     struct student *head;
186     struct student *stu;
187     int num;
188     head=Create();
189     Print(head);
190     printf("������Ҫɾ����ѧ��:");
191     scanf("%ld",&num);
192     while(num!=0)
193     {
194         head=Delete(head,num);
195         Print(head);
196         printf("������Ҫɾ����ѧ��:");
197         scanf("%ld",&num);
198     }
199     printf("������Ҫ����Ľڵ�:");
200     stu=(struct student *)malloc(LEN);
201     scanf("%ld %s",&stu->num,stu->name);
202     while(stu->num!=0)
203     {
204         head=Insert(head,stu);
205         printf("������Ҫ����Ľڵ�:");
206         stu=(struct student *)malloc(LEN);
207         scanf("%ld %s",&stu->num,stu->name);
208     }
209     Print(head);
210 }
