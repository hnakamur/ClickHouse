-- Tags: no-fasttest
DROP USER IF EXISTS 03172_user_invalid_bcrypt_hash;
CREATE USER 03172_user_invalid_bcrypt_hash IDENTIFIED WITH bcrypt_hash BY '012345678901234567890123456789012345678901234567890123456789'; -- { serverError BAD_ARGUMENTS }
