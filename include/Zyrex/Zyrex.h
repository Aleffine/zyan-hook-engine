/***************************************************************************************************

  Zyan Hook Engine (Zyrex)
  Version 1.0

  Remarks         : Freeware, Copyright must be included

  Original Author : Florian Bernd
  Modifications   :

 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in all
 * copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 * SOFTWARE.

***************************************************************************************************/

#ifndef _ZYREX_H_
#define _ZYREX_H_

#include <Windows.h>
#include <Zyrex/Defines.h>
#include <Zyrex/Status.h>

#ifdef __cplusplus
extern "C" {
#endif
/**
 * @brief   Begins a new transaction.
 *
 * @return  @c ZYREX_ERROR_SUCCESS if the function succeeded, an other zyrex status code, if not.
 */
ZYREX_DLLEXTERN ZyrexStatus ZyrexTransactionBegin();

/**
 * @brief   Adds a thread to the update list.
 *
 * @param   threadHandle    The handle of the thread.
 *
 * @return  @c ZYREX_ERROR_SUCCESS if the function succeeded, an other zyrex status code, if not.
 */
ZYREX_DLLEXTERN ZyrexStatus ZyrexUpdateThread(HANDLE threadHandle);

/**
 * @brief   Attaches an inline hook.
 *
 * @param   address     Pointer to the code address. Receives the trampoline address, if the
 *                      transaction succeeded.
 * @param   callback    The callback address.
 *
 * @return  @c ZYREX_ERROR_SUCCESS if the function succeeded, an other zyrex status code, if not.
 */
ZYREX_DLLEXTERN ZyrexStatus ZyrexAttachInlineHook(const void** address, const void* callback);

/**
 * @brief   Attaches an exception hook.
 *
 * @param   address     Pointer to the code address. Receives the trampoline address, if the
 *                      transaction succeeded.
 * @param   callback    The callback address.
 *
 * @return  @c ZYREX_ERROR_SUCCESS if the function succeeded, an other zyrex status code, if not.
 */
ZYREX_DLLEXTERN ZyrexStatus ZyrexAttachExceptionHook(const void** address, const void* callback);

/**
 * @brief   Attaches a context hook.
 *
 * @param   address     Pointer to the code address. Receives the trampoline address, if the
 *                      transaction succeeded.
 * @param   callback    The callback address.
 *
 * @return  @c ZYREX_ERROR_SUCCESS if the function succeeded, an other zyrex status code, if not.
 */
ZYREX_DLLEXTERN ZyrexStatus ZyrexAttachContextHook(const void** address, const void* callback);

// TODO: IAT/EAT, VTable, ..

/**
 * @brief   Commits the current transaction.
 *
 * @return  @c ZYREX_ERROR_SUCCESS if the function succeeded, an other zyrex status code, if not.
 */
ZYREX_DLLEXTERN ZyrexStatus ZyrexTransactionCommit();

/**
 * @brief   Commits the current transaction.
 *
 * @param   failedOperation Receives a pointer to the operation that failed the transaction.
 *
 * @return  @c ZYREX_ERROR_SUCCESS if the function succeeded, an other zyrex status code, if not.
 */
ZYREX_DLLEXTERN ZyrexStatus ZyrexTransactionCommitEx(const void** failedOperation);

/**
 * @brief   Cancels the current transaction.
 *
 * @return  @c ZYREX_ERROR_SUCCESS if the function succeeded, an other zyrex status code, if not.
 */
ZYREX_DLLEXTERN ZyrexStatus ZyrexTransactionAbort();

#ifdef __cplusplus
}
#endif
#endif /*_ZYREX_H_ */
