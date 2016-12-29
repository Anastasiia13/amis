-----------------------------
-- Populate Cusomer table
-----------------------------
INSERT INTO Customer (cust_name, cust_pass, cust_email, cust_phone) VALUES ('kpis', '$2a$11$87RaxDbpV8EDMAX87gBnZOtDWfDspoWS8OLxEjvIQYWlDhWl63dVC', 'kogut.iwan@gmail.com', '+380979835405');
INSERT INTO Customer (cust_name, cust_pass, cust_email, cust_phone) VALUES ('user', '$2a$11$SrHcUcBmp.0PnR820gXb6OXV8iIcxq476hkML1CGlWk7a2ow0kwca', 'olka@gmail.com', '+380979835405'); 

-----------------------------
-- Populate Supermarket table
-----------------------------
INSERT INTO Supermarket (supermarket_name, supermarket_image) VALUES ('����������', loadBlobFromFile ('supermarket_mega.jpg'));
INSERT INTO Supermarket (supermarket_name, supermarket_image) VALUES ('ѳ����', loadBlobFromFile ('supermarket_silpo.jpg'));
INSERT INTO Supermarket (supermarket_name, supermarket_image) VALUES ('������ ������', loadBlobFromFile ('supermarket_big_pocket.jpg'));
INSERT INTO Supermarket (supermarket_name, supermarket_image) VALUES ('���', loadBlobFromFile ('supermarket_atb.jpg'));

---------------------------------
-- Populate SectionProducts table
---------------------------------
INSERT INTO SectionProducts (section_name, section_image) VALUES ('������ ��������', loadBlobFromFile ('section_milk.jpg'));
INSERT INTO SectionProducts (section_name, section_image) VALUES ('�����', loadBlobFromFile ('section_buckwheat.jpg'));
INSERT INTO SectionProducts (section_name, section_image) VALUES ('������ ����', loadBlobFromFile ('section_hotdrinks.jpg'));
INSERT INTO SectionProducts (section_name, section_image) VALUES ('������', loadBlobFromFile ('section_fruits.jpg'));
INSERT INTO SectionProducts (section_name, section_image) VALUES ('�����', loadBlobFromFile ('section_vegetables.jpg'));

-------------------------
-- Populate Product table
-------------------------
INSERT INTO Product (prod_name, supermarket_name, section_name, prod_price, prod_desc, prod_image) VALUES ('������', 'ѳ����', '�����', '40', '������� ����� �� 1 ��.', loadBlobFromFile ('product_buckwheat.jpg'));
INSERT INTO Product (prod_name, supermarket_name, section_name, prod_price, prod_desc, prod_image) VALUES ('���', 'ѳ����', '�����', '47,64', '��� ������� �� 1 ��.', loadBlobFromFile ('product_rice.jpg'));
INSERT INTO Product (prod_name, supermarket_name, section_name, prod_price, prod_desc, prod_image) VALUES ('��� �����', 'ѳ����', '������ ����', '17,45', '������� ��� �����.', loadBlobFromFile ('product_tea.jpg'));
INSERT INTO Product (prod_name, supermarket_name, section_name, prod_price, prod_desc, prod_image) VALUES ('��� ����', 'ѳ����', '������ ����', '22,49', '������� ��� ����', loadBlobFromFile ('product_tea_batik.jpg'));
INSERT INTO Product (prod_name, supermarket_name, section_name, prod_price, prod_desc, prod_image) VALUES ('������', '����������', '������ ��������', '11,35', '������ �������', loadBlobFromFile ('product_yogurt.jpg'));
INSERT INTO Product (prod_name, supermarket_name, section_name, prod_price, prod_desc, prod_image) VALUES ('�����', '����������', '������', '29,75', '������ �� 1 ��.', loadBlobFromFile ('product_banana.jpg'));
INSERT INTO Product (prod_name, supermarket_name, section_name, prod_price, prod_desc, prod_image) VALUES ('���', '����������', '������ ��������', '19,99', '��� ��������', loadBlobFromFile ('product_milk_cheese.jpg'));
INSERT INTO Product (prod_name, supermarket_name, section_name, prod_price, prod_desc, prod_image) VALUES ('�����', '����������', '������', '8,45', '����� �� 1 ��.', loadBlobFromFile ('product_grusha.jpg'));
INSERT INTO Product (prod_name, supermarket_name, section_name, prod_price, prod_desc, prod_image) VALUES ('������', '����������', '������', '5,50', '������ �� 1 ��.', loadBlobFromFile ('product_apple.jpg'));
INSERT INTO Product (prod_name, supermarket_name, section_name, prod_price, prod_desc, prod_image) VALUES ('�����', 'ѳ����', '������ ��������', '9,65', '����� ���������', loadBlobFromFile ('product_kefir.jpg'));
INSERT INTO Product (prod_name, supermarket_name, section_name, prod_price, prod_desc, prod_image) VALUES ('�����', 'ѳ����', '������ ��������', '10,91', '����� ��������', loadBlobFromFile ('product_syrok.jpg'));
INSERT INTO Product (prod_name, supermarket_name, section_name, prod_price, prod_desc, prod_image) VALUES ('�������', 'ѳ����', '������ ��������', '16,99', '������� 18 % �������', loadBlobFromFile ('product_smetana.jpg'));
INSERT INTO Product (prod_name, supermarket_name, section_name, prod_price, prod_desc, prod_image) VALUES ('������', '����������', '�����', '2,00', '������ �� 1 ��.', loadBlobFromFile ('product_onion.jpg'));
INSERT INTO Product (prod_name, supermarket_name, section_name, prod_price, prod_desc, prod_image) VALUES ('��������', '����������', '�����', '7,49', '�������� �� 1 ��.', loadBlobFromFile ('product_potato.jpg'));
INSERT INTO Product (prod_name, supermarket_name, section_name, prod_price, prod_desc, prod_image) VALUES ('���', '������ ������', '������ ��������', '18,96', '��� ��������', loadBlobFromFile ('product_milk_cheese.jpg'));
INSERT INTO Product (prod_name, supermarket_name, section_name, prod_price, prod_desc, prod_image) VALUES ('�������', '������ ������', '������ ��������', '15,99', '������� 18 % �������', loadBlobFromFile ('product_smetana.jpg'));
INSERT INTO Product (prod_name, supermarket_name, section_name, prod_price, prod_desc, prod_image) VALUES ('�����', '������ ������', '������ ��������', '9,65', '����� ���������', loadBlobFromFile ('product_kefir.jpg'));
INSERT INTO Product (prod_name, supermarket_name, section_name, prod_price, prod_desc, prod_image) VALUES ('���', '������ ������', '�����', '47,84', '��� ������� �� 1 ��.', loadBlobFromFile ('product_rice.jpg'));
INSERT INTO Product (prod_name, supermarket_name, section_name, prod_price, prod_desc, prod_image) VALUES ('������', '������ ������', '�����', '35,65', '������� ����� �� 1 ��.', loadBlobFromFile ('product_buckwheat.jpg'));
INSERT INTO Product (prod_name, supermarket_name, section_name, prod_price, prod_desc, prod_image) VALUES ('�����', '������ ������', '�����', '22,58', '������� ����� �� 1 ��.', loadBlobFromFile ('product_pshono.jpg'));
INSERT INTO Product (prod_name, supermarket_name, section_name, prod_price, prod_desc, prod_image) VALUES ('���� �����', '������ ������', '������ ����', '34,45', '����� ���� �����', loadBlobFromFile ('product_coffee.jpg'));
INSERT INTO Product (prod_name, supermarket_name, section_name, prod_price, prod_desc, prod_image) VALUES ('������� ��� �����', '������ ������', '������ ����', '18,40', '������� �������� ��� �����', loadBlobFromFile ('product_tea_besida.jpg'));
INSERT INTO Product (prod_name, supermarket_name, section_name, prod_price, prod_desc, prod_image) VALUES ('������ ��� �����������', '������ ������', '������ ����', '18,84', '������� ������� ��� �����������', loadBlobFromFile ('product_tea_vysokogyr.jpg'));
INSERT INTO Product (prod_name, supermarket_name, section_name, prod_price, prod_desc, prod_image) VALUES ('��������', '������ ������', '������', '30,00', '��������� �� 1 ��.', loadBlobFromFile ('product_orange.jpg'));
INSERT INTO Product (prod_name, supermarket_name, section_name, prod_price, prod_desc, prod_image) VALUES ('������', '������ ������', '������', '68,15', '������� �� 1 ��.', loadBlobFromFile ('product_ananas.jpg'));
INSERT INTO Product (prod_name, supermarket_name, section_name, prod_price, prod_desc, prod_image) VALUES ('������', '������ ������', '������', '6', '������ �� 1 ��.', loadBlobFromFile ('product_apple.jpg'));
INSERT INTO Product (prod_name, supermarket_name, section_name, prod_price, prod_desc, prod_image) VALUES ('������ ������', '���', '������ ��������', '14,30', '������ ������', loadBlobFromFile ('product_aktyvia.jpg'));
INSERT INTO Product (prod_name, supermarket_name, section_name, prod_price, prod_desc, prod_image) VALUES ('�����', '���', '������ ��������', '9,92', '����� ��������', loadBlobFromFile ('product_syrok.jpg'));
INSERT INTO Product (prod_name, supermarket_name, section_name, prod_price, prod_desc, prod_image) VALUES ('������� �� �������������', '���', '������ ��������', '22,37', '������� ������������� 4 % �������', loadBlobFromFile ('product_ryachenka.jpg'));
INSERT INTO Product (prod_name, supermarket_name, section_name, prod_price, prod_desc, prod_image) VALUES ('��� ����', '���', '������ ����', '24,50', '������� ��� ����', loadBlobFromFile ('product_tea_batik.jpg'));
INSERT INTO Product (prod_name, supermarket_name, section_name, prod_price, prod_desc, prod_image) VALUES ('��� �������', '���', '������ ����', '19,82', '������� ��� �������', loadBlobFromFile ('product_tea_mayskyy.jpg'));
INSERT INTO Product (prod_name, supermarket_name, section_name, prod_price, prod_desc, prod_image) VALUES ('������� ��� �����', '���', '������ ����', '18,40', '������� �������� ��� �����', loadBlobFromFile ('product_tea_besida.jpg'));
INSERT INTO Product (prod_name, supermarket_name, section_name, prod_price, prod_desc, prod_image) VALUES ('��������', '���', '������', '12', '��������� �� 1 ��.', loadBlobFromFile ('product_mandarin.jpg'));
INSERT INTO Product (prod_name, supermarket_name, section_name, prod_price, prod_desc, prod_image) VALUES ('�����', '���', '������', '8', '����� �� 1 ��.', loadBlobFromFile ('product_grusha.jpg'));
INSERT INTO Product (prod_name, supermarket_name, section_name, prod_price, prod_desc, prod_image) VALUES ('��������', '���', '������', '2,2', '�������� �� 1 ��.', loadBlobFromFile ('product_strawberry.jpg'));
INSERT INTO Product (prod_name, supermarket_name, section_name, prod_price, prod_desc, prod_image) VALUES ('������', '���', '�����', '2,30', '������ �� 1 ��.', loadBlobFromFile ('product_morkva.jpg'));
INSERT INTO Product (prod_name, supermarket_name, section_name, prod_price, prod_desc, prod_image) VALUES ('������', '���', '�����', '2,50', '������ �� 1 ��.', loadBlobFromFile ('product_onion.jpg'));
INSERT INTO Product (prod_name, supermarket_name, section_name, prod_price, prod_desc, prod_image) VALUES ('�����', '���', '�����', '2,90', '����� �� 1 ��.', loadBlobFromFile ('product_beet.jpg'));

---------------------------
-- Populate OrderItem table
---------------------------
INSERT INTO OrderItem (cust_name, order_date, order_item, supermarket_name, prod_name, quantity) VALUES ('kpis', to_date('��. 18.12.2016 16:31:38','Dy dd.mm.yyyy hh24:mi:ss'), '1', '����������', '������', '1');
INSERT INTO OrderItem (cust_name, order_date, order_item, supermarket_name, prod_name, quantity) VALUES ('kpis', to_date('��. 18.12.2016 16:33:43','Dy dd.mm.yyyy hh24:mi:ss'), '1', '����������', '�����', '2');
INSERT INTO OrderItem (cust_name, order_date, order_item, supermarket_name, prod_name, quantity) VALUES ('kpis', to_date('��. 18.12.2016 16:33:43','Dy dd.mm.yyyy hh24:mi:ss'), '2', '����������', '��������', '1');
INSERT INTO OrderItem (cust_name, order_date, order_item, supermarket_name, prod_name, quantity) VALUES ('kpis', to_date('��. 18.12.2016 16:33:43','Dy dd.mm.yyyy hh24:mi:ss'), '3', 'ѳ����', '��� �����', '3');
INSERT INTO OrderItem (cust_name, order_date, order_item, supermarket_name, prod_name, quantity) VALUES ('user', to_date('��. 19.12.2016 13:24:40','Dy dd.mm.yyyy hh24:mi:ss'), '1', 'ѳ����', '��� �����', '2');