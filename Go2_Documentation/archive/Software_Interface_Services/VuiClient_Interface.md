# VuiClient Interface

# Volume and Lighting Service Interface

### VuiClient Class

`VuiClient` is the Client provided by the voice and lighting service status service. Through `VuiClient`, you can use RPC to control and retrieve information about Go2's volume and lighting (some functional interfaces are not yet open).

#### Interface Error Code List:

| **Error Code** | **Meaning** |
| --- | --- |
| 100 | The parameter passed in is incorrect |

#### Class and Interface Description:

| Class Name | Construction and Destruction |
| :---: | :--- |
| VuiClient | explicit VuiClient(); ~VuiClient(); |

| **Function Name** | **SetBrightness** |
| :---: | :--- |
| **Function Prototype** | `int32_t SetBrightness(int level)` |
| **Function Overview** | Sets the lighting brightness. |
| **Parameters** | **level**: Lighting brightness, value range 0~10. |
| **Return Value** | Returns 0 on successful call, otherwise returns the relevant error code. |
| **Notes** | |

| **Function Name** | **GetBrightness** |
| :---: | :--- |
| **Function Prototype** | `int32_t GetBrightness(int& level);` |
| **Function Overview** | Gets the lighting brightness. |
| **Parameters** | **level**: The returned lighting brightness. |
| **Return Value** | Returns 0 on successful call, otherwise returns the relevant error code. |
| **Notes** | |

| **Function Name** | **SetVolume** |
| :---: | :--- |
| **Function Prototype** | `int32_t SetVolume(int level);` |
| **Function Overview** | Sets the volume level. |
| **Parameters** | **level**: Volume level, value range 0~10. |
| **Return Value** | Returns 0 on successful call, otherwise returns the relevant error code. |
| **Notes** | |

| **Function Name** | **GetVolume** |
| :---: | :--- |
| **Function Prototype** | `int32_t GetVolume(int& level);` |
| **Function Overview** | Gets the volume level. |
| **Parameters** | **level**: The returned volume level. |
| **Return Value** | Returns 0 on successful call, otherwise returns the relevant error code. |
| **Notes** | |

---
