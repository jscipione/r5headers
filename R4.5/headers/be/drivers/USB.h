
/*
** USB.h
**
** Copyright 1999, Be Incorporated, All Rights Reserved.
**
*/

/* 
** WARNING WARNING WARNING WARNING WARNING WARNING WARNING WARNING WARNING 
** ------- ------- ------- ------- ------- ------- ------- ------- -------
** This is a preliminary API.  It will quite likely change.  Feedback is
** appreciated, but do not count on this being the final USB API.
** ------- ------- ------- ------- ------- ------- ------- ------- -------
** WARNING WARNING WARNING WARNING WARNING WARNING WARNING WARNING WARNING 
*/

#ifndef _USB_H
#define _USB_H

#include <BeBuild.h>
#include <SupportDefs.h>
#include <bus_manager.h>

#include <KernelExport.h>

#ifdef __cplusplus
extern "C" {
#endif

typedef struct usb_module_info usb_module_info;

/* request types (target & direction) for  send_request() */
/* cf USB Spec Rev 1.1, table 9-2, p 183 */
#define USB_REQTYPE_DEVICE_IN         0x80
#define USB_REQTYPE_DEVICE_OUT        0x00
#define USB_REQTYPE_INTERFACE_IN      0x81
#define USB_REQTYPE_INTERFACE_OUT     0x01
#define USB_REQTYPE_ENDPOINT_IN       0x82
#define USB_REQTYPE_ENDPOINT_OUT      0x02
#define USB_REQTYPE_OTHER_OUT         0x03
#define USB_REQTYPE_OTHER_IN          0x83

/* request types for send_request() */
/* cf USB Spec Rev 1.1, table 9-2, p 183 */
#define USB_REQTYPE_STANDARD          0x00
#define USB_REQTYPE_CLASS             0x20
#define USB_REQTYPE_VENDOR            0x40
#define USB_REQTYPE_RESERVED          0x60
#define USB_REQTYPE_MASK              0x9F

/* standard request values for send_request() */
/* cf USB Spec Rev 1.1, table 9-4, p 187 */
#define USB_REQUEST_GET_STATUS           0
#define USB_REQUEST_CLEAR_FEATURE        1
#define USB_REQUEST_SET_FEATURE          3
#define USB_REQUEST_SET_ADDRESS          5
#define USB_REQUEST_GET_DESCRIPTOR       6
#define USB_REQUEST_SET_DESCRIPTOR       7
#define USB_REQUEST_GET_CONFIGURATION    8
#define USB_REQUEST_SET_CONFIGURATION    9
#define USB_REQUEST_GET_INTERFACE       10
#define USB_REQUEST_SET_INTERFACE       11
#define USB_REQUEST_SYNCH_FRAME         12

/* used by {set,get}_descriptor(), {set,clear}_feature(), and get_status() */
/* cf USB Spec Rev 1.1, table 9-5, p 187 */
#define USB_DESCRIPTOR_DEVICE            1
#define USB_DESCRIPTOR_CONFIGURATION     2
#define USB_DESCRIPTOR_STRING            3
#define USB_DESCRIPTOR_INTERFACE         4
#define USB_DESCRIPTOR_ENDPOINT          5

#define USB_FEATURE_DEVICE               0
#define USB_FEATURE_INTERFACE            1
#define USB_FEATURE_ENDPOINT             2

#define USB_STATUS_DEVICE                0
#define USB_STATUS_INTERFACE             1
#define USB_STATUS_ENDPOINT              2


#ifndef USB_PRIVATE
/* usbdev is an opaque handle outside of the USBD implementation */
typedef struct _usbdev usb_device;
#endif
typedef struct _usb_interface usb_interface;
typedef struct _usb_endpoint usb_endpoint;

/* defines for the notify(...) status */
#define USB_DEVICE_ADDED          1
#define USB_DEVICE_REMOVED        2
		
#define USB_ANY_CLASS           0x00  /* all devices */
#define USB_ANY_SUBCLASS        0x00  /* all subclasses of specified device class */
#define USB_ANY_VENDOR          0x00  /* any vendor of specified class and subclass */
#define USB_ANY_PRODUCT         0x00  /* any product of specified class, subclass, and vendor */

#define USB_SUPPORT_DESCRIPTOR '_USB'

typedef struct _usb_support_descriptor {
	uint32 dev_desc_type;     
	uint8 dev_class;
	uint8 dev_subclass;
	uint16 vendor;
	uint16 product;
} usb_support_descriptor;

/* ie, I support any hub device:
        usb_support_descriptor hub_devs = 
             { USB_SUPPORT_DESCRIPTOR, 9, 0, 0, 0 };
*/

typedef struct { 
	/* cf USB Spec Rev 1.1, table 9-7, p 197 */
	uint8 length;
	uint8 descriptor_type;          /* USB_DESCRIPTOR_DEVICE */
	uint16 usb_version;             /* USB_DESCRIPTOR_DEVICE_LENGTH */
	uint8 device_class;
	uint8 device_subclass;
	uint8 device_protocol;
	uint8 max_packet_size_0;
	uint16 vendor_id;
	uint16 product_id;
	uint16 device_version;
	uint8 manufacturer;
	uint8 product;
	uint8 serial_number;
	uint8 num_configurations;
} _PACKED usb_device_descriptor;

typedef struct {
	/* cf USB Spec Rev 1.1, table 9-8, p 199 */
	uint8 length;
	uint8 descriptor_type;          /* USB_DESCRIPTOR_CONFIGURATION */
	uint16 total_length;            /* USB_DESCRIPTOR_CONFIGURATION_LENGTH */
	uint8 number_interfaces;
	uint8 configuration_value;
	uint8 configuration;
	uint8 attributes;
	uint8 max_power;
} _PACKED usb_configuration_descriptor;

typedef struct {
	/* cf USB Spec Rev 1.1, table 9-9, p 202 */
	uint8 length;
	uint8 descriptor_type;          /* USB_DESCRIPTOR_INTERFACE */
	uint8 interface_number;         /* USB_DESCRIPTOR_INTERFACE_LENGTH  */
	uint8 alternate_setting;
	uint8 num_endpoints;
	uint8 interface_class;
	uint8 interface_subclass;
	uint8 interface_protocol;
	uint8 interface;
} _PACKED usb_interface_descriptor;

typedef struct {
	/* cf USB Spec Rev 1.1, table 9-10, p 203 */
	uint8 length;
	uint8 descriptor_type;          /* USB_DESCRIPTOR_ENDPOINT */
	uint8 endpoint_address;         /* USB_DESCRIPTOR_ENDPOINT_LENGTH */
	uint8 attributes;
	uint16 max_packet_size;
	uint8 interval;
} _PACKED usb_endpoint_descriptor;

typedef struct {
	/* cf USB Spec Rev 1.1, table 9-12, p 205 */
	uint8 length;                   /* USB_DESCRIPTOR_STRING */
	uint8 descriptor_type;
	uchar string[1];
} _PACKED usb_string_descriptor;

typedef struct {
	uint8 length;
	uint8 descriptor_type;
	uint8 data[1];
} _PACKED usb_generic_descriptor;

typedef union {
	usb_generic_descriptor generic;
	usb_device_descriptor device;
	usb_interface_descriptor interface;
	usb_endpoint_descriptor endpoint;
	usb_configuration_descriptor configuration;
	usb_string_descriptor string;
} usb_descriptor;

typedef struct {
	usb_endpoint_descriptor *descr;
	usb_endpoint *handle;
} usb_endpoint_info;
 
typedef struct _usb_interface_info {
	/* descriptor and handle of this interface */
	usb_interface_descriptor *descr;
	usb_interface *handle;
	
	/* endpoints in this interface */	
	size_t endpoint_count;
	usb_endpoint_info *endpoint;
	
	/* chain to next alternate interface */
	struct _usb_interface_info *alt;
} usb_interface_info;

typedef struct {
	/* descriptor of this config */
	usb_configuration_descriptor *descr; 
	
	/* interfaces in this config */
	size_t interface_count; 
	usb_interface_info *interface;
	
	/* currently selected interfaces */
	usb_interface_info **active;
	
	/* unparsed descriptors in this config */
	size_t generic_count; 
	usb_generic_descriptor **generic;

	/* no user servicable parts */
	void *raw_data;	
} usb_configuration_info;

		
struct _usbd_param_hdr;

typedef void (*usb_notify_func)(usb_device *dev, uint32 status);
typedef void (*usb_callback_func)(void *cookie, uint32 status, void *data, uint32 actual_len);
				
struct usb_module_info {
	bus_manager_info	binfo;

#if 0
	/* USBD Interface Funcs -- left in at Dmitriy's request*/
	uint32 (*USBD_Get_Version)(void);
	uint32 (*USBD_GetDefaultDeviceHandle)(uint32 *def_dev, uint32 *def_ls_dev);
	uint32 (*USBDCall)(struct _usbd_param_hdr *);
#endif 
	
	/* inform the bus manager of our intent to support a set of devices */
	status_t (*register_driver)(char *driver_name,
								usb_support_descriptor *devs, size_t count);								
	status_t (*unregister_driver)(char *driver_name);

	/* request notification from the bus manager for add/remove of devices we
	   support */
	status_t (*install_notify)(char *driver_name, usb_notify_func notify);
	status_t (*uninstall_notify)(char *driver_name);
	
	/* refcount operators for drivers to reserve/release devices */
	void (*get_device)(usb_device *dev);
	void (*put_device)(usb_device *dev);

	/* get the device descriptor */
	usb_device_descriptor *(*get_device_descriptor)(usb_device *d);
	
	/* get the nth supported configuration */	
	usb_configuration_info *(*get_nth_configuration)(usb_device *dev, uint index);

	/* get the active configuration */
	usb_configuration_info *(*get_configuration)(usb_device *dev);
	
	/* set the active configuration */	
	status_t (*set_configuration)(usb_device *dev,
								  usb_configuration_info *configuration); 

	status_t (*set_alt_interface)(usb_device *dev, usb_configuration_info *cfg,
								  usb_interface_info *ifc);
	
	/* standard device requests -- convenience functions */
	/* obj: NULL=device or a usb_endpoint* or usb_interface* */
	status_t (*set_feature)(usb_device *d, void *obj, uint16 selector);
	status_t (*clear_feature)(usb_device *d, void *obj, uint16 selector);
	status_t (*get_status)(usb_device *d, void *obj, uint16 *status);
	status_t (*get_descriptor)(usb_device *d, uint8 type, uint8 index, uint16 lang,
							   void *data, size_t len, size_t *actual_len);

	/* generic device request function */	
	status_t (*send_request)(usb_device *d, uint8 request_type, uint8 request,
							 uint16 value, uint16 index, uint16 length,
							 void *data, size_t data_len, size_t *actual_len);

	/* async stuff */
	status_t (*queue_interrupt)(usb_endpoint *e, void *data, size_t len,
								usb_callback_func notify, void *cookie);
	
	status_t (*queue_bulk)(usb_endpoint *e, void *data, size_t len,
						   usb_callback_func notify, void *cookie);
								
	status_t (*queue_isochronous)(usb_endpoint *e, ...); /* unimplemented */

	status_t (*queue_request)(usb_device *d, uint8 request_type, uint8 request,
							  uint16 value, uint16 index, uint16 length,
							  void *data, size_t data_len, 
							  usb_callback_func notify, void *cookie);
							 
	status_t (*set_pipe_policy)(usb_endpoint *e, ...); /* unimplemented */
	
	/* cancel pending async requests to an endpoint */
	status_t (*cancel_queued_transfers)(usb_endpoint *e); 
	
	/* tuning, timeouts, etc */
	status_t (*set_param)(usb_device *d, uint32 param, uint32 value);	
};

	
#define	B_USB_MODULE_NAME		"bus_managers/usb/v1"

#ifdef __cplusplus
}
#endif

#endif
