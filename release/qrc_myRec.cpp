/****************************************************************************
** Resource object code
**
** Created: Tue Feb 26 09:33:21 2013
**      by: The Resource Compiler for Qt version 4.8.2
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <QtCore/qglobal.h>

static const unsigned char qt_resource_data[] = {
  // D:/QT/FactoryView/wk.ico
  0x0,0x0,0x1,0x17,
  0x0,
  0x0,0x16,0x3e,0x78,0x9c,0xed,0x98,0x4b,0x6e,0xc2,0x30,0x10,0x86,0x7f,0xc7,0x52,
  0xcd,0x2e,0x3b,0xc4,0xa2,0x12,0x5b,0x96,0xdc,0x0,0x8e,0xc4,0x11,0xe6,0x20,0x1c,
  0x26,0x47,0xc9,0x11,0x58,0x76,0x51,0xc9,0xc,0xaf,0x24,0xc4,0x33,0x90,0xd4,0xa8,
  0x40,0x3b,0x5f,0x1e,0xa3,0xfc,0xf3,0xf0,0xd8,0x89,0xbc,0x8,0xe0,0xf8,0x58,0xaf,
  0xc1,0xf7,0x9,0x16,0x53,0x80,0x4f,0x2c,0xf8,0x62,0x9,0x84,0x93,0xae,0x11,0x63,
  0xc4,0x76,0xa6,0xfb,0xd,0xc3,0xf8,0xbb,0x14,0x86,0x61,0x18,0xcf,0xc2,0xb5,0x8,
  0x52,0x57,0x4e,0x3d,0x7,0x9f,0x10,0xa9,0xe6,0xb,0xe9,0x85,0x10,0x2b,0x85,0xa9,
  0xb2,0xa0,0xd,0xa,0x54,0xaa,0xe6,0xe6,0xa7,0x53,0xd2,0xc4,0x61,0x4b,0x7a,0xd6,
  0xb4,0x6c,0x29,0x78,0x8,0x37,0xde,0xc9,0xc8,0xfc,0x5c,0x72,0x87,0x7f,0xf7,0xfc,
  0xa7,0xac,0x5f,0xf6,0xf7,0xe3,0xf4,0xef,0x77,0x74,0x7,0x8f,0x9b,0x7f,0xd2,0x4e,
  0x7f,0x7b,0x13,0x3a,0xe8,0xb,0xfd,0x8,0xb5,0x9c,0xe8,0x1f,0x9f,0xff,0xe0,0xf9,
  0xa7,0x1b,0xfa,0xcd,0x19,0xbb,0xd4,0xdd,0x9,0xb8,0x3f,0x42,0x7e,0xbe,0x61,0x18,
  0xc6,0x3f,0x25,0xbe,0x18,0x54,0xee,0x30,0xff,0x86,0xa3,0xc0,0xf6,0xb,0x9e,0xdc,
  0xe,0xa1,0x46,0x49,0x60,0x5b,0x61,0xde,0xda,0xd,0x3b,0xb1,0x22,0x2c,0x51,0x0,
  0x91,0x8e,0x7f,0x33,0x5c,0x63,0x9b,0x7a,0xc7,0x67,0xaf,0xda,0xeb,0xb8,0x4b,0x9d,
  0x43,0xdd,0x93,0x6d,0xfc,0x1,0x1e,0x9f,0xdc,0x47,0x20,0x4f,0x1f,0x3c,0xf4,0xd9,
  0xb6,0xfe,0x2a,0x54,0xbe,0x6,0xf7,0x1d,0x6a,0xee,0xf9,0x62,0x7f,0x69,0xd9,0x7e,
  0xcc,0x1e,0xda,0x89,0x98,0xfc,
  
};

static const unsigned char qt_resource_name[] = {
  // wk.ico
  0x0,0x6,
  0x7,0xde,0x4f,0x9f,
  0x0,0x77,
  0x0,0x6b,0x0,0x2e,0x0,0x69,0x0,0x63,0x0,0x6f,
  
};

static const unsigned char qt_resource_struct[] = {
  // :
  0x0,0x0,0x0,0x0,0x0,0x2,0x0,0x0,0x0,0x1,0x0,0x0,0x0,0x1,
  // :/wk.ico
  0x0,0x0,0x0,0x0,0x0,0x1,0x0,0x0,0x0,0x1,0x0,0x0,0x0,0x0,

};

QT_BEGIN_NAMESPACE

extern Q_CORE_EXPORT bool qRegisterResourceData
    (int, const unsigned char *, const unsigned char *, const unsigned char *);

extern Q_CORE_EXPORT bool qUnregisterResourceData
    (int, const unsigned char *, const unsigned char *, const unsigned char *);

QT_END_NAMESPACE


int QT_MANGLE_NAMESPACE(qInitResources_myRec)()
{
    QT_PREPEND_NAMESPACE(qRegisterResourceData)
        (0x01, qt_resource_struct, qt_resource_name, qt_resource_data);
    return 1;
}

Q_CONSTRUCTOR_FUNCTION(QT_MANGLE_NAMESPACE(qInitResources_myRec))

int QT_MANGLE_NAMESPACE(qCleanupResources_myRec)()
{
    QT_PREPEND_NAMESPACE(qUnregisterResourceData)
       (0x01, qt_resource_struct, qt_resource_name, qt_resource_data);
    return 1;
}

Q_DESTRUCTOR_FUNCTION(QT_MANGLE_NAMESPACE(qCleanupResources_myRec))

