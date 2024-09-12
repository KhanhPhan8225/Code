CREATE DATABASE ThucTap
GO
USE ThucTap
GO

CREATE TABLE Khoa(
	makhoa char(10),
	tenkhoa char(30),
	dienthoai char(10)
	CONSTRAINT pk_Khoa PRIMARY KEY(makhoa)
)

CREATE TABLE GiangVien(
	magv int,
	hotengv char(30),
	luong  int,
	makhoa char(10)
	CONSTRAINT pk_GV PRIMARY KEY(magv)
)

CREATE TABLE SinhVien(
	masv int,
	hotensv char(30),
	makhoa char(10),
	namsinh int,
	quequan char(30)
	CONSTRAINT pk_SV PRIMARY KEY(masv)
)

CREATE TABLE DeTai(
	madt char(10),
	tendt char(10),
	kinhphi int,
	NoiThucTap char(30)
	CONSTRAINT pk_DT PRIMARY KEY(madt)
)

CREATE TABLE HuongDan(
	masv int,
	madt char(10),
	magv int,
	ketqua int,
	CONSTRAINT fk_HD PRIMARY KEY(masv, madt)
)
-- Khoa
INSERT INTO Khoa VALUES('DIALY','Dia Ly','0123456789')
INSERT INTO Khoa VALUES('QLTN','Quan Ly Tai Nguyen','0341234561')
INSERT INTO Khoa VALUES('TOAN','Toan','0345671382')

-- GiangVien
INSERT INTO GiangVien VALUES(1,'Nguyen Van A',10000000,'DIALY')
INSERT INTO GiangVien VALUES(2,'Nguyen Van B',8000000,'DIALY')
INSERT INTO GiangVien VALUES(3,'Nguyen Van C',15000000,'DIALY')
INSERT INTO GiangVien VALUES(4,'Nguyen Van D',11000000,'QLTN')
INSERT INTO GiangVien VALUES(5,'Nguyen Van E',5000000,'QLTN')
INSERT INTO GiangVien VALUES(5,'Nguyen Van F',9000000,'TOAN')
INSERT INTO GiangVien VALUES(5,'Nguyen Van L',6000000,'TOAN')


-- SinhVien
INSERT INTO SinhVien VALUES(1,'Le Van Son','DIALY',1999,'Ha Noi')
INSERT INTO SinhVien VALUES(2,'Nguyen Van G','DIALY',1998,'Ha Noi')
INSERT INTO SinhVien VALUES(3,'Nguyen Van H','DIALY',1997,'Ha Noi')
INSERT INTO SinhVien VALUES(4,'Nguyen Van I','QLTN',1996,'Ha Noi')
INSERT INTO SinhVien VALUES(5,'Nguyen Van K','QLTN',1995,'Ha Noi')
INSERT INTO SinhVien VALUES(5,'Nguyen Van M','TOAN',1994,'Ha Noi')
INSERT INTO SinhVien VALUES(5,'Nguyen Van N','TOAN',1996,'Ha Noi')

-- DeTai
INSERT INTO DeTai VALUES('DT1','De Tai 1',1000000,'Ha Noi')
INSERT INTO DeTai VALUES('DT2','De Tai 2',2000000,'Ha Noi')
INSERT INTO DeTai VALUES('DT3','De Tai 3',3000000,'Ha Noi')
INSERT INTO DeTai VALUES('DT4','De Tai 4',4000000,'Ha Noi')
INSERT INTO DeTai VALUES('DT5','De Tai 5',5000000,'Ha Noi')

-- HuongDan
INSERT INTO HuongDan VALUES(1,'DT1',1,10)
INSERT INTO HuongDan VALUES(2,'DT2',2,9)
INSERT INTO HuongDan VALUES(3,'DT3',3,8)
INSERT INTO HuongDan VALUES(4,'DT4',4,7)
INSERT INTO HuongDan VALUES(5,'DT5',5,6)


SELECT magv, hotengv, tenkhoa FROM GiangVien, Khoa WHERE GiangVien.makhoa = Khoa.makhoa
-- Sử dụng SQL để xuất ra mã số, họ tên, tên khoa của các giảng viên hướng dẫn từ 3 sinh viên trở lên
SELECT magv, hotengv, tenkhoa FROM GiangVien, Khoa WHERE GiangVien.makhoa = Khoa.makhoa AND magv IN (SELECT magv FROM HuongDan GROUP BY magv HAVING COUNT(masv) >= 3)
-- Sử dụng SQL để xuất ra thông tin về những sinh viên chưa có điểm thực tập
SELECT masv, hotensv, tendt FROM SinhVien, DeTai WHERE SinhVien.masv NOT IN (SELECT masv FROM HuongDan)
-- Thực hiện lệnh SQL xuất ra số điện thoại của khoa mà sinh viên có tên ‘Le van son’ đang theo học 
SELECT dienthoai FROM Khoa WHERE makhoa = (SELECT makhoa FROM SinhVien WHERE hotensv = 'Le Van Son')
-- Sử dụng lệnh truy vấn SQL lấy ra mã số và tên các đề tài có nhiều hơn 2 sinh viên tham gia thực tập.
SELECT madt, tendt FROM DeTai WHERE madt IN (SELECT madt FROM HuongDan GROUP BY madt HAVING COUNT(masv) > 2)
-- Sử dụng câu lệnh truy vấn SQL lấy ra mã số, tên đề tài của đề tài có kinh phí cao nhất.
SELECT madt, tendt FROM DeTai WHERE kinhphi = (SELECT MAX(kinhphi) FROM DeTai)
-- Sử dụng câu lệnh SQL xuất ra Tên khoa, Số lượng sinh viên của mỗi khoa.
SELECT tenkhoa, COUNT(masv) FROM Khoa, SinhVien WHERE Khoa.makhoa = SinhVien.makhoa GROUP BY tenkhoa
-- Sử dụng truy vấn SQL xuất ra mã số, họ tên và điểm của các sinh viên khoa ‘DIALY và QLTN’.
SELECT SinhVien.masv, SinhVien.hotensv, HuongDan.ketqua FROM SinhVien JOIN HuongDan ON SinhVien.masv = HuongDan.masv JOIN GiangVien ON HuongDan.magv = GiangVien.magv JOIN Khoa ON GiangVien.makhoa = Khoa.makhoa WHERE Khoa.tenkhoa IN ('DIALY', 'QLTN');
-- Sử dụng câu lệnh SQL xuất ra danh sách gồm Mã số, Họ tên và Tuổi của các sinh viên khoa ‘TOAN’
SELECT masv, hotensv, 2024 - namsinh AS Tuoi FROM SinhVien, Khoa WHERE SinhVien.makhoa = Khoa.makhoa AND Khoa.tenkhoa = 'TOAN'